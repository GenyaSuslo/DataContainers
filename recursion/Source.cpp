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
	cout << "введите номер этажа"; cin >> n;
	elevator(n);*/
	double a; int n;
	cout << "введите число: "; cin>>a;
	cout << "введите степень: "; cin>>n;
	cout<<Power(a, n);
	int c;
	cout << endl << "введите число для вычисления факториала: "; cin >> c;
	cout << factorial(c);
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
		return 1;
	else return Power(a, n - 1)*a;
	//cout << a << endl;
}
int factorial(int n)
{
	cout << n << "\t";
	if (n == 0)
		return 1;
	else return factorial(n - 1) * n;
	
}