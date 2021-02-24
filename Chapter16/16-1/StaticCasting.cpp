#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGuage;
public:
	Car(int fuel)
		: fuelGuage(fuel)
	{ }

	void ShowCarState()
	{
		cout << "Fuel remain: " << fuelGuage << endl;
	}
};

class Truck : public Car
{
private:
	int freightWeight;
public:
	Truck(int fuel, int weight)
		: Car(fuel), freightWeight(weight)
	{ }

	void showTruckState()
	{
		ShowCarState();
		cout << "Freight weight: " << freightWeight << endl;
	}
};

int main()
{
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = static_cast<Truck*>(pcar1);
	ptruck1->showTruckState();
	cout << endl;

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = static_cast<Truck*>(pcar2);
	ptruck2->showTruckState();

	return 0;
}
