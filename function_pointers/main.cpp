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
	void (*p_hello)() = hello; //void*-void pointer(��������� �� 'void', ����� ������� ����� ��������� ������ ����)
	//��� �������������'void pointer' ����������� ����� ��������������� ��� � ������� ���
	
	p_hello();

	int(*p_sum)(int, int)=sum;//������������� ������� � �����������,����������� ������ ��� ������ ����������� ����������
	//cout << sum(2, 3) << endl; 
	cout << sum << endl;
	cout << p_sum(2,3) << endl;


}