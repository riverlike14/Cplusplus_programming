#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

void Car::InitMembers(char * ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGuage = fuel;
	curSpeed = 0;
}


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
