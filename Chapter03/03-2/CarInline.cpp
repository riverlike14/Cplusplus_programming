#include <cstring>
#include "CarInline.h"

using namespace std;

void Car::InitMembers(char * ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGuage = fuel;
	curSpeed = 0;
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
