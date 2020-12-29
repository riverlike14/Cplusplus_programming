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

class CONTAC600
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const
	{
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient
{
public:
	void TakeCONTAC600(const CONTAC600 &cap)
	{
		cap.Take();
	}
};

int main()
{
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);

	return 0;
}
