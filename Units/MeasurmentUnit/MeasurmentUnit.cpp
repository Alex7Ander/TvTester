//---------------------------------------------------------------------------
#pragma hdrstop
#include "MeasurmentUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------
Device::Device(string IpAddr, int Port)
{
  this->port = Port;
  this->deviceIpAddr = IpAddr;
}
//---------------------------------------------------------------
int Device::connectToDevice()
{
  int goodDone;
  WSADATA WSAData;
  goodDone = WSAStartup(MAKEWORD(2,NULL), &WSAData);
  if (goodDone == 0){
    this->deviceSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (this->deviceSocket!=INVALID_SOCKET){
         sockAddrInfo.sin_family = AF_INET;
         sockAddrInfo.sin_port = htons(5025);
	 sockAddrInfo.sin_addr.S_un.S_addr=inet_addr(this->deviceIpAddr.c_str());
	 goodDone = connect(deviceSocket, (sockaddr*)(&sockAddrInfo), sizeof(sockAddrInfo));
	 if (goodDone==0){
            char *bufS = "*IDN?\n";
            send (this->deviceSocket, bufS, (int)strlen(bufS), 0);
            char bufR[1024];
            int size;
            size = recv(this->deviceSocket, bufR, 1024, 0);
            delete bufS;
            return 0;
         }
	 else{
	   return 3;
	 }
     }
     else{
        return 2;
     }
  }
  else{
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
void Generator::setPower(double Power)
{
  send (this->deviceSocket, (char*)("UNIT:POW DBUV\n"), (int)strlen("UNIT:POW DBUV\n"), 0);
  char cmdStart[]="POW:AMPL ";
  char level[10];
  gcvt(Power,9,level);
  char *cmd = new char[16+strlen(level)];
  strcat(cmd, cmdStart);
  strcat(cmd, level);
  strcat(cmd, " DBUV\n");
  send (this->deviceSocket, cmd, (int)strlen(cmd), 0);
}
//---------------------------------------------------------------
void Generator::setFreq(double Freq)
{
  char *bufS;
  char s1[] = "FREQ ";
  char s3[] = " MHZ\n";
  char s2[7];
  gcvt(Freq,7, s2);
  char *cmd = new char[strlen(s1)+strlen(s2)+strlen(s3)+1];
  strcat(cmd, s1);
  strcat(cmd, s2);
  strcat(cmd, s3);
  send (this->deviceSocket, cmd, (int)strlen(cmd), 0);
}
//---------------------------------------------------------------
void Generator::turnOn()
{
  send (this->deviceSocket, (char*)("OUTP:ALL ON\n"), (int)strlen("OUTP:ALL ON\n"), 0);
}
//---------------------------------------------------------------
void Generator::turnOff()
{
  send (this->deviceSocket, (char*)("OUTP:ALL OFF\n"), (int)strlen("OUTP:ALL OFF\n"), 0);
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
double PowerMetr::measPower()
{
send (this->deviceSocket, (char*)("SENS:UNIT DBUV\n"), (int)strlen("SENS:UNIT DBUV\n"), 0);
send (this->deviceSocket, (char*)("READ?\n"), (int)strlen("READ?\n"), 0);
char bufR[50];
recv(this->deviceSocket, bufR, 50, 0);
double res = atof(bufR);
return res;
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
Measurement::Measurement(string ipGen, int portGen, string ipPowerMetr, int portPowerMetr)
{
  this->countOfFreq = 0;
  this->currentFreq = 0;
  this->generator = new Generator(ipGen, portGen);
  this->powerDetector = new PowerMetr(ipPowerMetr, portPowerMetr);
}
//---------------------------------------------------------------
Measurement::readFreqTable(string filePath)
{
  this->freq.clear();
  char bufF[8];
  ifstream fileIn(filePath.c_str());
  do {
     fileIn.getline(bufF,8);
     this->freq.push_back(atof(bufF));
  } while (!fileIn.eof());
  fileIn.close();
  this->countOfFreq = this->freq.size();
return 0;
}
//---------------------------------------------------------------
void Measurement::startMeasurement(double initialPower)
{
  this->generator->connectToDevice();
  Sleep(500);
  this->powerDetector->connectToDevice();
  Sleep(500);
  this->generator->setPower(initialPower);
}
//---------------------------------------------------------------
void Measurement::nextStep(int step)
{
  this->generator->setFreq(this->freq[step]);
  Sleep(300);
  this->generator->turnOn();
  Sleep(300);
  this->truePower[step] = this->powerDetector->measPower();
}
//---------------------------------------------------------------
void Measurement::takeResult(int resIndex, double resPower)
{
  this->verPower[resIndex] = resPower;
  this->deltaPower[resIndex] = this->truePower[resIndex] - this->verPower[resIndex];
  currentFreq++;
}
//---------------------------------------------------------------
int Measurement::saveTxtFile(string filePath)
{
  ofstream protocolFile;
  try{
    protocolFile.open(filePath.c_str());
    protocolFile << "׳אסעמעא, ֳֳצ\tPטחל dBuV\tPהויסע dBuV\tdelta" << endl;
    for (int i=0; i<this->currentFreq; i++)
      protocolFile << this->freq[i] << "\t" << this->verPower[i] << "\t" << this->truePower[i] << "\t" << this->deltaPower[i] << endl;
    return 0;
  }catch(...){return 1;}
}
//---------------------------------------------------------------
int Measurement::createProtocol(string protocolPath, verificationInfo *Info)
{
//
return 0;
}
//---------------------------------------------------------------
void Measurement::stopMeasurement()
{
  this->generator->turnOff();
  this->generator->disconnectFromDevice();
  this->powerDetector->disconnectFromDevice();
}
