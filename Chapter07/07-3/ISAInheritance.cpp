#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
	char owner[50];

public:
	Computer(char* name)
	{
		strcpy(owner, name);
	}

	void Calculate()
	{
		cout << "Calculate your order..." << endl;
	}
};

class LaptopComputer : public Computer
{
private:
	int Battery;

public:
	LaptopComputer(char* name, int initCharge)
		: Computer(name), Battery(initCharge)
	{ }

	void Charging()
	{
		Battery += 5;
	}

	void UseBattery()
	{
		Battery -= 1;
	}

	void MovingCalculate()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "Need to charge the battery..." << endl;
		} else {
			Calculate();
			UseBattery();
		}
	}

	int GetBatteryInfo()
	{
		return Battery;
	}
};

class TabletComputer : public LaptopComputer
{
private:
	char registeredPen[50];

public:
	TabletComputer(char* name, int initCharge, char* pen)
		: LaptopComputer(name, initCharge)
	{
		strcpy(registeredPen, pen);
	}

	void write(char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "Need to charge the battery..." << endl;
		} else if (strcmp(registeredPen, penInfo) != 0) {
			cout << "Not a registered pen..." << endl;
		} else {
			cout << "It is writing now..." << endl;
			UseBattery();
		}
	}
};

int main()
{
	LaptopComputer lc("Lee", 5);
	TabletComputer tc("Jung", 5, "ISE-241-242");

	lc.MovingCalculate();
	tc.write("ISE-241-242");

	return 0;
}
