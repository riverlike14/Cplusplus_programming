#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;

public:
	Temporary(int n)
		:num(n)
	{
		cout << "Create obj: " << num << endl;
	}

	~Temporary()
	{
		cout << "Destroy obj: " << num << endl;
	}

	void ShowTempInfo() const
	{
		cout << "My num is " << num << endl;
	}
};

int main()
{
	Temporary(100);
	cout << "************** After Make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "************** After Make!" << endl << endl;

	const Temporary &ref = Temporary(300);
	cout << "************** End of Main!" << endl << endl;

	return 0;
}
