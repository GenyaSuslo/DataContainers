#include<iostream>
using namespace std;
#define tab "\t"
#define delimeter "\n----------------------------------------------------------\n"
class List
{
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
		friend class List;
	}*Head, *Tail;//сюда можно вписывать создаваемые объекты класса
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
			cout << "BItCionstructor: \t" << this << endl;
		}
		~ConstBaseIterator()
		{
			cout << "BItConstructor:\t" << this << endl;
		}
		bool operator==(const ConstBaseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ConstBaseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
	};
public:
	class ConstIterator :public ConstBaseIterator
	{
		//Element* Temp; она объявлена в базовом классе
	public:
		ConstIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
		{
			cout << "ItConstructor:\t" << this << endl;
		}
		~ConstIterator()
		{
			cout<<"ItDestructor:\t"<<this<<endl;
		}
		ConstIterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ConstIterator operator++(int)
		{
			ConstIterator old = *this;
			Temp = Temp -> pNext;
			return old;
		}
		ConstIterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ConstIterator& operator--(int)
		{
			ConstIterator old = *this;
			Temp = Temp->pPrev;
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
	class ConstReversIterator:public ConstBaseIterator
	{
		//Element* Temp;
	public:
		ConstReversIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
		{
			cout << "RItConstructor:\t" << this << endl;
		}
		~ConstReversIterator()
		{
			cout << "RItConstructor:\t" << this << endl;
		}
		ConstReversIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ConstReversIterator operator++(int)
		{
			ConstReversIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		ConstReversIterator operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ConstReversIterator operator--(int)
		{
			ConstReversIterator old = *this;
			Temp = Temp->pNext;
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
		Iterator(Element* Temp=nullptr):ConstIterator(Temp)
		{
			cout << "ItConstructor:\t" << this << endl;
		}
		int& operator*()
		{
			return Temp->Data;
		};
		class ReversIterator :public ConstReversIterator
		{
		public:
			ReversIterator(Element* Temp = nullptr) :ConstReversIterator(Temp)
			{
				cout << "RItConstructor:\t" << this << endl;
			}
			int& operator*()
			{
				return Temp->Data;
			}
		};
	ConstIterator cbegin()const
	{
		return Head;
	}
	ConstIterator cend()const
	{
		return nullptr;
	}
	ConstReversIterator crbegin()const
	{
		return Tail;
	}
	ConstReversIterator crend()const
	{
		return nullptr;
	}
	Iterator begin()
		{
			return Head;
		}
	Iterator end()
	{
		return nullptr;
	}
	ReversIterator begin()
	{
		return Tail;
	}
	ReversIterator end()
	{
		return nullptr;
	}
	List()
	{
		Head = Tail = nullptr;
		cout << "LConstructor: \t" << this << endl;
	}
	List(const std::initializer_list<int>& il) :List()
	{
		for (int const* it = il.begin(); it != il.end();++it)
		{
			push_back(*it);
		}
	}
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		cout << "LDestructor: \t" << this << endl;
	}

	//					Adding Elements:
	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)Head = Tail = new Element(Data);
		else Head = Head->pPrev = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr) Head = Tail = new Element(Data);
		else Tail = Tail->pNext = new Element(Data,nullptr,Tail);
		size++;
	}
	void insert(int Data, int Index)
	{
		if (Index == 0)return push_front(Data);
		if (Index >= size)return push_back(Data);
		Element* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
		}
		Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
		size++;
	}
	//					Remove Elements:
	void pop_front()
	{
		if (Head==nullptr && Tail==nullptr)return;
		if(Head==Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head -> pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == Tail)return pop_front();
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	void erase(int Index)
	{
		if (Index == 0)return pop_front();
		if (Index >= size)return;
		Element* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
	}
	
	//					Methods:
	void print() const
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
	}
	void reverse_print()const
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
	}
};
List operator+(const List& left, const List& right)
{
	List cat = left;
	for (List::ConstIterator it = right.begin() != right.end(); ++it)
	{
		(*it) *= 10;
		cat.push_back(*it);
	}
	return cat;
}
//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "введите размер списка:"; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	cout << delimeter << endl;
	list.reverse_print();
	//list.push_back(rand() % 100);
	int Index;
	int Value;
	cout << "введите индекс добавляемого элемента:"; cin >> Index;
	cout << "введите значение добавляемого элемента:"; cin >> Value;
	list.insert(Value, Index);
	list.print();
	cout << delimeter << endl;
	list.reverse_print();
#endif  BASE_CHECK
	
	List list1 = { 3,5,8,13,21 };
	//list1.print();
	for (int i : list1)cout << i << tab; cout << endl;
	/*for (List::Iterator it = list1.end(); it != list1.begin(); it--)
	{
		cout << *it << tab;
	};
	cout << endl;*/
	/*for (List::ReversIterator it = list1.rbegin(); it != list1.rend(); ++it)
	{
		cout << *it << tab;
	};
	cout << endl;*/
	for (List::Iterator it = list1.begin(); it != list1.end(); ++it)
	{
		(*it) *= 10;
	}
	List list2 = { 34,55,89 };
	for (int i : list2)cout << i << tab; cout << endl;

	List list3 = list1 + list2;
	for (int i : list1)cout << i << tab; cout << endl;
	for (int i : list2)cout << i << tab; cout << endl;
	for (int i : list3)cout << i << tab; cout << endl;

}