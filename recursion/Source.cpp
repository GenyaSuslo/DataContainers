#include<iostream>
using namespace std;

void elevator(int floor);
double Power(double a, int n);

void main()
{

	setlocale(LC_ALL, "");

	//cout << "Hello World";
	//main();
	/*int n;
	cout << "������� ����� �����"; cin >> n;
	elevator(n);*/
	double a; int n;
	cout << "������� �����: "; cin>>a;
	cout << "������� �������: "; cin>>n;
	Power(a, n);
}
void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "�� � �������" << endl;
		return;
	}
	cout << "�� �� " << floor << " �����\n";
	elevator(floor-1);
	cout << "�� �� " << floor << " �����\n";

}
double Power(double a, int n)
{
	if (n == 0)
		return a;
	Power(a * a, n - 1);
	cout << a << endl;
}