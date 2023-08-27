#pragma once
#include<iostream>
using namespace std;
#define tab "\t"
#define delimeter "\n----------------------------------------------------------\n"
//#define DEBUG
template<typename T>class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr) : Data(Data), pNext(pNext), pPrev(pPrev)
		{
#ifdef DEBUG
			cout << "EConstructor: \t" << this << endl;
#endif DEBUG
		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor: \t" << this << endl;
#endif // DEBUG

		}
		friend class List;
	}*Head, * Tail;//сюда можно вписывать создаваемые объекты класса
	//Element* Head;
	//Element* Tail
	unsigned int size;
	class ConstBaseIterator
	{
	protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp) :Temp(Temp)
		{
#ifdef DEBUG

			cout << "BItConstructor: \t" << this << endl;
#endif // DEBUG

		}
		~ConstBaseIterator()
		{
#ifdef DEBUG
			cout << "BItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		bool operator==(const ConstBaseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ConstBaseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const T& operator*()const
		{
			return Temp->Data;
		}
	};
public:
	class ConstIterator :public ConstBaseIterator
	{
		//Element* Temp; она объ€влена в базовом классе
	public:
		ConstIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~ConstIterator()
		{
#ifdef DEBUG
			cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG

		}
		ConstIterator& operator++()
		{
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
			return *this;
		}
		ConstIterator operator++(int)
		{
			ConstIterator old = *this;
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
			return old;
		}
		ConstIterator& operator--()
		{
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
			return *this;
		}
		ConstIterator& operator--(int)
		{
			ConstIterator old = *this;
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
			return old;
		}
		//это уже есть в базовом классе
		/*bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}*/
		/*int& operator*()
		{
			return Temp->Data;
		}*/
	};
	class ConstReversIterator :public ConstBaseIterator
	{
		//Element* Temp;
	public:
		ConstReversIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~ConstReversIterator()
		{
#ifdef DEBUG
			cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		ConstReversIterator& operator++()
		{
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
			return *this;
		}
		ConstReversIterator operator++(int)
		{
			ConstReversIterator old = *this;
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
			return old;
		}
		ConstReversIterator operator--()
		{
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
			return *this;
		}
		ConstReversIterator operator--(int)
		{
			ConstReversIterator old = *this;
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
			return old;
		}
		//это уже есть в базовом классе
		/*bool operator==(const ReversIterator& other) const
			{
			return this->Temp == other.Temp;
			}
		bool operator!=(const ReversIterator& other) const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}*/
		/*int& operator*()
		{
			return Temp->Data;
		}*/

	};
	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp = nullptr) :ConstIterator(Temp)
		{
#ifdef DEBUG
			cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		T& operator*()
		{
			return ConstBaseIterator::Temp->Data;
		}
	};
	class ReversIterator :public ConstReversIterator
	{
	public:
		ReversIterator(Element* Temp = nullptr) :ConstReversIterator(Temp)
		{
#ifdef DEBUG
			cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		T& operator*()
		{
			return ConstBaseIterator::Temp->Data;
		}
	};
	ConstIterator cbegin()const;
	ConstIterator cend()const;
	ConstReversIterator crbegin()const;
	ConstReversIterator crend()const;
	Iterator begin();
	Iterator end();
	ReversIterator rbegin();
	ReversIterator rend();

	List();
	List(const std::initializer_list<T>& il);
	List(const List<T>& other);
	~List();
	//					Operators:
	List<T>& operator= (const List<T>& other);

	//					Adding Elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int Index);
	//					Remove Elements:
	void pop_front();
	void pop_back();
	void erase(int Index);

	//					Methods:
	void print() const;
	void reverse_print()const;
};

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right);
