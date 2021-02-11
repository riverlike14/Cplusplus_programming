#include <iostream>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum)
		: bullet(bnum)
	{ }

	void Shot()
	{
		cout << "BBANG!!" << endl;
		bullet--;
	}

	int BulletLeft() const
	{
		return bullet;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	Police(const Police& ref)
		: handcuffs(ref.handcuffs)
	{
		cout << "Copy constructor called...!" << endl;
		pistol = new Gun(0);
		*pistol = *(ref.pistol);
	}

	Police& operator=(const Police& ref)
	{
		cout << "Assignment operator called...!" << endl;
		handcuffs = ref.handcuffs;
		if (pistol != NULL)
			delete pistol;
		pistol = new Gun(*(ref.pistol));
		return *this;
	}

	void PutHandCuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}

	void Shot()
	{
		if (pistol == NULL)
			cout << "FAKE BBANG..." << endl;
		else
			pistol->Shot();
	}

	void ShowPoliceInfo() const
	{
		cout << "Bullet: " << pistol->BulletLeft() << endl;
		cout << "Handcuff: " << handcuffs << endl;
	}
	
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main()
{
	Police pol1(5, 3);
	Police pol2 = pol1;
	pol2.PutHandCuff();
	pol2.Shot();
	pol2.ShowPoliceInfo();

	Police pol3(2, 4);
	pol3 = pol2;
	pol3.PutHandCuff();
	pol3.Shot();
	pol3.ShowPoliceInfo();

	return 0;
}
