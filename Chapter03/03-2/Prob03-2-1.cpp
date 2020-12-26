#include <iostream>
using namespace std;

class Calculator
{
private:
	int addCount;
	int subCount;
	int mulCount;
	int divCount;
public:
	void Init();
	double Add(double x, double y);
	double Min(double x, double y);
	double Mul(double x, double y);
	double Div(double x, double y);
	void ShowOpCount();
};

void Calculator::Init()
{
	addCount = 0;
	subCount = 0;
	mulCount = 0;
	divCount = 0;
}

double Calculator::Add(double x, double y)
{
	addCount++;
	return x + y;
}

double Calculator::Min(double x, double y)
{
	subCount++;
	return x - y;
}

double Calculator::Mul(double x, double y)
{
	mulCount++;
	return x * y;
}

double Calculator::Div(double x, double y)
{
	divCount++;
	return x / y;
}

void Calculator::ShowOpCount()
{
	cout << "덧셈: " << addCount << ' ';
	cout << "뺄셈: " << subCount << ' ';
	cout << "곱셈: " << mulCount << ' ';
	cout << "나눗셈: " << divCount << ' ';
	cout << endl;
}

int main()
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();

	return 0;
}
