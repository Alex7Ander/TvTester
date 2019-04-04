#include "mainTv.h"

int main()
{
	Prog *myProg = new Prog();
	bool isWorking = true;
	char inp;
	while (isWorking)
	{
		myProg->work();
		cout << "Programm finished" << endl;
		cout << "Input any symbol, except 0 for one more time.\nAnd 0 to exit." << endl;		
		cin >> inp;
		if (inp=='0') isWorking = false;
	}
	
	return 0;
}
//bcc32.exe mainTv.cpp Prog.cpp