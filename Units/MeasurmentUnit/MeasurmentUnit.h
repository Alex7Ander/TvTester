//---------------------------------------------------------------------------
#ifndef MeasurmentUnitH
#define MeasurmentUnitH
//---------------------------------------------------------------------------
#include <string>
#include <vector.h>
#include <fstream.h>
#include <winsock2.h>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
struct verificationInfo
{
	string deviceType;
	string deviceSerialNumber;
	string deviceOwner;
};
//---------------------------------------------------------------------------
class Device
{
public:
        Device(string IpAddr, int Port);
        int connectToDevice();
        int disconnectFromDevice();
        void controlProcedure();

protected:
        int port;
        string deviceIpAddr;
        string deviceIDN;
        SOCKET deviceSocket;
        sockaddr_in sockAddrInfo;
};
//---------------------------------------------------------------------------
class Generator : public Device
{
private:
        double freq;
        double power;

public:
        Generator(string IpAddr, int Port) : Device(IpAddr, Port){}
        void setFreq(double Freq);
        double getFreq(){return freq;}
        void setPower(double Power);
        double getPower(){return power;}
        void turnOn();
        void turnOff();
};
//---------------------------------------------------------------------------
class PowerMetr : public Device
{
public:
        PowerMetr(string IpAddr, int Port) : Device(IpAddr, Port){}
        double measPower();
};
//---------------------------------------------------------------------------
class Measurement
{
private:
        Generator *generator;
        PowerMetr *powerDetector;
        vector<double> freq;
        vector<double> verPower;
        vector<double> truePower;
        vector<double> deltaPower;
        int countOfFreq;
        int currentFreq;
        
public:
       Measurement(string ipGen, int poertGen, string ipPowerMetr, int portPowerMetr);
       void startMeasurement(double initialPower);
       void takeResult(int resIndex, double resPower);
       void stopMeasurement();
       readFreqTable(string filePath);
       void nextStep(int step);
       int saveTxtFile(string filePath);
       int createProtocol(string protocolPath, verificationInfo *Info);
       int getCountOfFreq(){return countOfFreq;}
       double getFreq(int at){return freq[at];}
};
#endif
