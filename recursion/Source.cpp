#include<iostream>
using namespace std;

void elevator(int floor);
double Power(double a, int n);
int factorial(int n);

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
	cout<<Power(a, n);
	int c;
	cout << endl << "������� ����� ��� ���������� ����������: "; cin >> c;
	cout << factorial(c);
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
		return 1;
	else return Power(a, n - 1)*a;
	//cout << a << endl;
}
int factorial(int n)
{
	if (n == 0)
		return 1;
	cout << n << "\t";
	/*else*/ return factorial(n - 1) * n;
	
}