#include <iostream>
using namespace std;

class Car
{
private:
	int gasolineGuage;

public:
	Car(int gas)
		: gasolineGuage(gas)
	{ }

	int GetGasGuage() const
	{
		return gasolineGuage;
	}
};

class HybridCar : public Car
{
private:
	int electricGuage;

public:
	HybridCar(int gas, int elec)
		: Car(gas), electricGuage(elec)
	{  }

	int GetElecGuage() const
	{
		return electricGuage;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGuage;

public:
	HybridWaterCar(int gas, int elec, int water)
		: HybridCar(gas, elec), waterGuage(water)
	{  }

	void ShowCurrentGuage() const
	{
		cout << "Remaining gas: " << GetGasGuage() << endl;
		cout << "Remaining electricity: " << GetElecGuage() << endl;
		cout << "Remaining water: " << waterGuage << endl;
	}
};

int main()
{
	HybridWaterCar hcar1(100, 30, 50);
	hcar1.ShowCurrentGuage();

	return 0;
}
