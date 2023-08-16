//ForwardList
#include<iostream>
using namespace std;
#define tab "\t"

class Element
{
	int Data; //значение
	Element* pNext;//адрес следующего элемента
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
	Element* Head;//содержит адрес начального элемента списка
public:
	ForwardList()
	{
		Head = nullptr;//если список пуст его голова указывает на 0
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList& other)
	{
		cout << "CopyConstructor: \t" << this << endl;
		//deepCopy:
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
	}
	~ForwardList()
		{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
		}
	//					Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		cout << "LCopyAssignment: \t" << this << endl;
		//Deep copy:
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
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
		//1)создаем новый элемент
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
		//Element* Temp = Head;// Temp итератор
		//
		//while (Temp)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//	Temp = Temp->pNext;
		//}
		cout << "Head: " << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp<< tab << Temp->Data << tab << Temp->pNext << endl;
	}
	
};


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	//list.push_back(123);
	list = list;
	list.Print();
	/*list.pop_front();
	list.pop_back();
	list.Print();*/
	/*int value;
	int index;
	cout << "введите индекс элемента: "; cin >> index;
	cout << "введите значение элемента: "; cin >> value;
	
	list.insert(value, index);
	list.Print();

	cout << "введите индекс элемента: "; cin >> index;
	list.erase(index);
	list.Print();*/
	//ForwardList list2 = list;//CopyConstructor
	ForwardList list2;
	list2 = list;//copy assignment
	list2.Print();
}