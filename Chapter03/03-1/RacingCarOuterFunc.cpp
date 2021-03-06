#include <iostream>
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

struct Car
{
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGuage;
	int curSpeed;

	void ShowCarState();
	void Accel();
	void Break();
};


void Car::ShowCarState()
{
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGuage << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl;
	cout << endl;
}

void Car::Accel()
{
	if (fuelGuage <= 0)
		return;
	fuelGuage -= CAR_CONST::FUEL_STEP;

	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
		curSpeed = CAR_CONST::MAX_SPD;
	else
		curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if (curSpeed - CAR_CONST::BRK_STEP < 0)
		curSpeed = 0;
	else
		curSpeed -= CAR_CONST::BRK_STEP;
}

int main()
{
	Car run99 = {"run99", 100, 0};
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77 = {"sped77", 100, 0};
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	
	return 0;
}
