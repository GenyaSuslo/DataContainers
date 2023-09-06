#include<iostream>
using namespace std;
void hello()
{
	cout << "Hello" << endl;
}
int sum(int a, int b)
{
	return a + b;
}


void main()
{
	setlocale(LC_ALL, "");
	void (*p_hello)() = hello; //void*-void pointer(указатель на 'void', может хранить адрес абсолютно любого типа)
	//при разименовании'void pointer' обязательно нужно преобразовывать его в целевой тип
	
	p_hello();

	int(*p_sum)(int, int)=sum;//инициализация функции с параметрами,указывается только тип данных принимаемых параметров
	//cout << sum(2, 3) << endl; 
	cout << sum << endl;
	cout << p_sum(2,3) << endl;


}