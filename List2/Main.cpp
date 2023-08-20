#include<iostream>

using std::cin;
using std::cout;
using std::endl;


class Element
{
	int Data;
	Element* pNext;
	Element* pPrev;
public:
	Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) : Data(Data), pNext(pNext), pPrev(pPrev)
	{
		cout << "EConstructor: \t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor: \t" << this << endl;
	}
	friend class Iterator;
};
class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) : Temp(Temp)
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
	int operator*()
	{
		return Temp->Data;
	}
};
class ForwardList
{
	Element* Head;
	Element* Tail;
public:
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return Tail;
	}
	ForwardList()
	{
		Head = nullptr;
		Tail = nullptr;
		cout << "LConstructor: \t" << this << endl;
	}
	ForwardList(const std::initializer_list<int>& il) : ForwardList()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}

	//					Operators

	ForwardList& operator=(const ForwardList& other)
	{

	}

	//					Adding Elements:
	void push_front(int Data)
	{
		//нужна какая то проверка чтоб не записывался всегда 1 элемент
		
		Head = new Element(Data, Head);
		if (Tail = nullptr)Tail = Head;
		//else Tail = new Element(Data, Tail);
	}
	void push_back(int Data)
	{
		Tail = new Element(Data, Tail);
		if (Head = nullptr)Head = Tail;
		//else Head = new Element(Data, Tail);
	}




};