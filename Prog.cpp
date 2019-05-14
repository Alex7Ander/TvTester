#include "Prog.h"
//---------------------------------------------------------------
Prog::Prog()
{
	this->messageString = "Hello. Welcome to TV tester controller programm\nLet's start!";
}
//---------------------------------------------------------------
void Prog::work()
{
	cout << messageString.c_str() << endl;
	cout << "Input generator ip address:";
	string addr;
	char msg[20];
	cin >> msg;
	addr = msg;
	Device *generator = new Device(addr);
	int connected = generator->connectToDevice();
	if (!connected)
	{
		verifiedInfo Info;
		generator->readFreqFromFile(askFreqTable());  
		generator->askVerifiedInfo(&Info);
		generator->controlProcedure();
		generator->createProtocolFile(&Info);
		generator->disconnectFromDevice();
	}
	
	return;
}
//---------------------------------------------------------------
int Prog::askFreqTable()
{
	int tableCode, countOfTables;
	char bufIn[256];
	cout << "Input code of freq table" << endl;
	cout << "Help: " << endl;
	fstream helpFile("list.dat");
	helpFile.getline(bufIn, 256);
	countOfTables = atoi(bufIn);
	for (int i=0; i<countOfTables; i++)
	{
		helpFile.getline(bufIn, 256);
		cout << bufIn << endl;
	}
	
	bool noError = false;
	while (noError == false)
	{
		cin >> tableCode;
		if (tableCode==1 || tableCode==2) noError=true;
		else cout << "Wrong table code! Try one more time:" << endl;
	}
	return tableCode;
}
//---------------------------------------------------------------
/*
class Device code realisation:
*/
//---------------------------------------------------------------
Device::Device(string ipAddr)
{
	this->deviceIpAddr = ipAddr;
	this->countOfFreq = 0;
}
//---------------------------------------------------------------
int Device::connectToDevice()
{
	int goodDone;
	WSADATA WSAData;
	goodDone = WSAStartup(MAKEWORD(2,NULL), &WSAData);
	if (goodDone == 0)
	{
		this->deviceSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (this->deviceSocket!=INVALID_SOCKET)
		{
			sockAddrInfo.sin_family = AF_INET;
			sockAddrInfo.sin_port = htons(5025);
			sockAddrInfo.sin_addr.S_un.S_addr=inet_addr(this->deviceIpAddr.c_str());
			goodDone = connect(deviceSocket, (sockaddr*)(&sockAddrInfo), sizeof(sockAddrInfo));
			if (goodDone==0)
			{
				char *bufS = "*IDN?\n";
				send (this->deviceSocket, bufS, (int)strlen(bufS), 0);
				char bufR[1024];
				int size;
				size = recv(this->deviceSocket, bufR, 1024, 0);
				cout << "Good connection. You generator is: ";
				for (int k=0; k<size; k++) cout << bufR[k];
				cout << endl;
				delete bufS;
				return 0;
			}
			else
			{
				cout << "Error 3: No connection" << endl;
				return 3;
			}
		}
		else
		{
			cout << "Error 2: Invalid socket" << endl;
			return 2;
		}
	}
	else
	{
		cout << "Error 1: WSAStartup is not initialized" << endl;
		return 1;
	}	
}
//---------------------------------------------------------------
int Device::disconnectFromDevice()
{
	closesocket(this->deviceSocket);
	WSACleanup();
	return 0;
}
//---------------------------------------------------------------
int Device::readFreqFromFile(int listParametr)
{
	char bufF[255];
	char stopStr[] = "end";
	string str;
	ifstream fileIn("freq.dat");
	//Ищем нужный список
	do
	{
		fileIn.getline(bufF,255);
	} while (atoi(bufF)!=listParametr);
	//Нашли нужный список, теперь считываем частоты
	do
	{
		fileIn.getline(bufF,255);
		this->freq.push_back(atof(bufF));
		this->countOfFreq++;
	} while (strcmp(stopStr, bufF));
	countOfFreq--; //Тут делаем декримент, поскольку когда была прочтена остоновочная строка, то пременная countOfFreq все равно  увеличилась на 1
	return 0;
}
//---------------------------------------------------------------
void Device::controlProcedure()
{
	string msg;
	char *bufS;
	char s1[] = "FREQ ";
	char s3[] = " MHZ\n";
	char s2[7];
	verifiedRes = new float[this->countOfFreq];
	headRes = new float[this->countOfFreq];
	difference = new float[this->countOfFreq];
	
	//Подготовка
	//Зададим амплитуду генерируемого сигнала и единицы измерения
	send (this->deviceSocket, (char*)("UNIT:POW DBUV\n"), (int)strlen("UNIT:POW DBUV\n"), 0);
	char cmdStart[]="POW:AMPL ";
	char level[10];
	cout << "Enter power level (recomended value is 100 dBuV): ";
	cin >> level;
	char *cmd = new char[16+strlen(level)];
	strcat(cmd, cmdStart);
	strcat(cmd, level);
	strcat(cmd, " DBUV\n");
	//cout << "Command is: " << cmd << endl;
	send (this->deviceSocket, cmd, (int)strlen(cmd), 0); //"POW:AMPL "+level+"DBM\n"
	
	for (int i=0; i<this->countOfFreq; i++)
	{ 
		//Отправляем SCPI команду на установку частоты:
		gcvt(this->freq.at(i),7, s2);
		cout << endl <<"Step #"<< i+1 << "\tf= " << freq.at(i) <<endl;
		
		bufS = new char[strlen(s1)+strlen(s2)+strlen(s3)+1];
		strcat(bufS, s1);
		strcat(bufS, s2);
		strcat(bufS, s3);

		send (this->deviceSocket, bufS, (int)strlen(bufS), 0);	
		for (int j=0; j<strlen(bufS); j++) bufS[j]='\0';
		
		send (this->deviceSocket, (char*)("OUTP:ALL ON\n\n"), (int)strlen("OUTP:ALL ON\n\n"), 0);
		
		//Запрашиваем данные с поверяемого прибора:
		cout << "Enter data from the verified instrument: ";
		cin >> verifiedRes[i];
				
		//Получаем данные с головки измерительной
		send (this->deviceSocket, (char*)("SENS:UNIT DBUV\n"), (int)strlen("SENS:UNIT DBUV\n"), 0);
		send (this->deviceSocket, (char*)("READ?\n"), (int)strlen("READ?\n"), 0);
		
		char bufR[50];
		int size;
		cout << "Waiting data" << endl;
		size = recv(this->deviceSocket, bufR, 50, 0);
		headRes[i]=atof(bufR);
		//cout << "Result from head: " << headRes[i] << endl;
		
		//Проводим рассчеты:
		difference[i] = headRes[i] - verifiedRes[i];
		
		//Выводим строку с подсчетом промежуточных результатов:
		cout << "F, GHz\tP\tP(head)\tDiff" << endl;
		cout << this->freq.at(i) << "\t" << verifiedRes[i] << "\t" << headRes[i] << "\t" << difference[i] << endl;
		
		//Просим подтвердить переход к следующей частоте:
		send (this->deviceSocket, (char*)("OUTP:ALL OFF\n\n"), (int)strlen("OUTP:ALL OFF\n\n"), 0);
		system("pause");
	}
	 
	delete bufS;
	return;
}
//---------------------------------------------------------------
void Device::askVerifiedInfo(verifiedInfo *Info)
{
	char inputData[256];
	const char separator = '\n';
	int t;
	
	cout << "Inputint information about verification device" << endl;	
	cin.getline(inputData, 256, separator);

	cout << "Enter device model: ";
	cin.getline(inputData, 256, separator);
	Info->deviceModel = inputData;
	
	cout << "Enter device serial number: ";
	cin.getline(inputData, 256, separator);
	Info->deviceSerialNumber = inputData;
	
	cout << "Enter device owner: ";	
	cin.getline(inputData, 256, separator);
	Info->deviceOwner = inputData;

	delete inputData;
}
//---------------------------------------------------------------
int Device::createProtocolFile(verifiedInfo *Info)
{
	char Path[1024];
	cout << "Enter file path: ";
	cin >> Path;
	ofstream protocolFile;
	protocolFile.open(Path);
	protocolFile << "Протокол поверки: " << Info->deviceModel.c_str() << endl;
	protocolFile << "Серийный номер: " << Info->deviceSerialNumber.c_str() << endl;
	protocolFile << "Владелец: " << Info->deviceOwner.c_str() << endl << endl;
	protocolFile << "Частота, ГГц\tPизм dBuV\tPдейст dBuV\tdelta" << endl;
	for (int i=0; i<this->countOfFreq; i++)
		protocolFile << this->freq.at(i) << "\t" << this->verifiedRes[i] << "\t" << this->headRes[i] << "\t" << this->difference[i] << endl;
	cout << "File saved" << endl;
	return 0;
}
//---------------------------------------------------------------



















