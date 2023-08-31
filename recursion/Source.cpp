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
	cout << "введите номер этажа"; cin >> n;
	elevator(n);*/
	double a; int n;
	cout << "введите число: "; cin>>a;
	cout << "введите степень: "; cin>>n;
	Power(a, n);
}
void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "Вы в подвале" << endl;
		return;
	}
	cout << "Вы на " << floor << " этаже\n";
	elevator(floor-1);
	cout << "Вы на " << floor << " этаже\n";

}
double Power(double a, int n)
{
	if (n == 0)
		return a;
	Power(a * a, n - 1);
	cout << a << endl;
}