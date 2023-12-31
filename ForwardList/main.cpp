﻿//ForwardList
#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;;

#define tab "\t"
#define delimeter "\n-----------------------------"

class ForwardList;
ForwardList operator+(const ForwardList& left, const ForwardList& right);

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
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
	friend class Iterator;
};
class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
		cout << "ItConstructor: \t" << this << endl;
	}
	~Iterator()
	{
		cout << "ItDestructor: \t" << this << endl;
	}
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}
	int operator *()
	{
		return Temp->Data;
	}
	
};
class ForwardList
{
	Element* Head;//содержит адрес начального элемента списка
public:
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ForwardList()
	{
		Head = nullptr;//если список пуст его голова указывает на 0
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const std::initializer_list<int>& il):ForwardList()
	{

		//begin() - возвращает значение в начало контейнера
		//end() - возвращает итератор на конец контейнера

		cout<<typeid(il.begin()).name() << endl;//узнаем тип данных объекта il.begin()
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}

	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		cout << "LCopyConstructor: \t" << this << endl;
		//deepCopy:
		/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);*/
		*this = other;
	}

	ForwardList(ForwardList&& other):ForwardList()//ForwardList&& - r-values reference
	{
		/*this->Head = other.Head;
		other.Head = nullptr;*/
		*this = std::move(other);//функция move() принудит.вызывает MoveAssigment для объекта
		cout << "FMoveConstructor: \t" << this << endl;
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
	ForwardList& operator=(ForwardList&& other)
	{
		while (Head)pop_front();
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveAssigment: \t"<< this << endl;
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
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (Element* Temp = right.Head; Temp; Temp = Temp->pNext)cat.push_back(Temp->Data);
	return cat;
}

//#define BASE_CHECK
//#define OPERATOR_PLUS_CHECK
//#define RANGE_BASE_FOR_ARRAY 
//#define RANGE_BASE_FOR_LIST
#define MOVE_SEMANTIC_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
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
#endif BASE_CHECK;

#ifdef OPERATOR_PLUS_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.Print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.Print();

	ForwardList list3 = list1 + list2;
	list3.Print();

#endif OPERATOR_PLUS_CHECK

#ifdef RANGE_BASE_FOR_ARRAY

	int arr[] = { 3,5,8,13,21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

	
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;

	
#endif range_base_for_array

#ifdef  RANGE_BASE_FOR_LIST
	ForwardList list = { 3,5,8,13,21 };
	list.Print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
#endif  RANGE_BASE_FOR_LIST

#ifdef MOVE_SEMANTIC_CHECK

	ForwardList list1 = { 3,5,8,13,21 };
	for (int i : list1)cout << i << tab; cout << endl;

	ForwardList list2 = { 34,55,89 };
	for (int i : list2)cout << i << tab; cout << endl;

	cout << delimeter << endl;
	ForwardList list3 = list1 + list2;//MoveConstructor
	cout<<delimeter<<endl;
	for (int i : list3)cout << i << tab; cout << endl;


#endif  MOVE_SEMANTIC_CHECK

	


}