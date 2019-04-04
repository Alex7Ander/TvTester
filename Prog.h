#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <vector.h>
#include <windows.h>
#include <winsock2.h>

using namespace std;
struct verifiedInfo
{
	string deviceModel;
	string deviceSerialNumber;
	string deviceOwner;
};

class Prog
{
	private:
		string messageString;
	
	public:
		Prog(); //конструктор класса
		void work();
		int askFreqTable();
};

class Device
{
	public:
		Device(string ipAddr);			//class constructor with 1 parametr
		int connectToDevice();  	    //connecting to the generator
		int disconnectFromDevice();     //disconnecting from generator
		int readFreqFromFile(int listParametr);
		void askVerifiedInfo(verifiedInfo *Info);
		void controlProcedure();
		int createProtocolFile(verifiedInfo *Info);
		vector<float> freq;
		
	private:
		string deviceIpAddr;
		SOCKET deviceSocket;
		sockaddr_in sockAddrInfo;
		int countOfFreq;
		float *verifiedRes; 
		float *headRes; 
		float *difference; 
};

