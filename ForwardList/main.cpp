//ForwardList
#include<iostream>
using namespace std;

class Element
{
	int Data; //��������
	Element* pNext;//����� ���������� ��������
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
};

class ForwardList
{
	Element* Head;//�������� ����� ���������� �������� ������
public:
	ForwardList()
	{
		Head = nullptr;//���� ������ ���� ��� ������ ��������� �� 0
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
		{
			cout << "LDestructor:\t" << this << endl;
		}

	//					Adding elements:
	void push_front(int Data)
	{
		Head = new Element(Data);
		
	}
};


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	
}