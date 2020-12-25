#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car
{
	char gamerID[ID_LEN];
	int fuelGuage;
	int curSpeed;

	void ShowCarState()
	{
		cout << "소유자ID: " << gamerID << endl;
		cout << "연료량: " << fuelGuage << "%" << endl;
		cout << "현재속도: " << curSpeed << "km/s" << endl;
		cout << endl;
	}

	void Accel()
	{
		if (fuelGuage <= 0)
			return;
		fuelGuage -= FUEL_STEP;

		if (curSpeed + ACC_STEP >= MAX_SPD)
			curSpeed = MAX_SPD;
		else
			curSpeed += ACC_STEP;
	}

	void Break()
	{
		if (curSpeed - BRK_STEP < 0)
			curSpeed = 0;
		else
			curSpeed -= BRK_STEP;
	}
};


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
