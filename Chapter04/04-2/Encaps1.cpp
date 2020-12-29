#include <iostream>
using namespace std;

class SinivelCap
{
public:
	void Take() const
	{
		cout << "Stop runny nose...!" << endl;
	}
};

class SneezeCap
{
public:
	void Take() const
	{
		cout << "Stop coughing...!" << endl;
	}
};

class SnuffleCap
{
public:
	void Take() const
	{
		cout << "Make your throat clear...!" << endl;
	}
};

class ColdPatient
{
public:
	void TakeSinivelCap(const SinivelCap &cap) const
	{
		cap.Take();
	}
	void TakeSneezeCap(const SneezeCap &cap) const
	{
		cap.Take();
	}
	void TakeSnuffleCap(const SnuffleCap &cap) const
	{
		cap.Take();
	}
};

int main()
{
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);

	return 0;
}
