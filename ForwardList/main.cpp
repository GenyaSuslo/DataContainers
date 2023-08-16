//ForwardList
#include<iostream>
using namespace std;
#define tab "\t"

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
	friend class ForwardList;
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
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
		}

	//					Adding elements:
	void push_front(int Data)
	{
		Head = new Element(Data, Head);
	}

	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
	}

	//					Delete Elements:
	void pop_front()
	{
		Element* erased = Head;
		Head = Head->pNext;
		delete erased;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
	}
	void insert(int Data, int Index)
	{
		if (Index == 0)return push_front(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index-1; i++)
			if(Temp->pNext)
				Temp = Temp->pNext;
		//1)������� ����� �������
		Element* New = new Element(Data);
		//2)
		New->pNext = Temp->pNext;
		//3)
		Temp->pNext = New;
	}
	void erase(int Index)
	{
		if (Index == 0)return pop_back();
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			if (Temp ->pNext);
				Temp = Temp->pNext;
		Element* erased = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete erased;
		
	}



	//					Methods:
	void Print()const
	{
		Element* Temp = Head;// Temp ��������
		
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
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
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	//list.push_back(123);
	list.Print();
	/*list.pop_front();
	list.pop_back();
	list.Print();*/
	int value;
	int index;
	cout << "������� ������ ��������: "; cin >> index;
	cout << "������� �������� ��������: "; cin >> value;
	
	list.insert(value, index);
	list.Print();

	cout << "������� ������ ��������: "; cin >> index;
	list.erase(index);
	list.Print();
	
}