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
		//Element* Temp; она объявлена в базовом классе
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
			ConstBaseIterator::Temp =ConstBaseIterator::Temp->pNext;
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
	ReversIterator rbegin()
	{
		return Tail;
	}
	ReversIterator rend()
	{
		return nullptr;
	}


	List()
	{
		Head = Tail = nullptr;
		cout << "LConstructor: \t" << this << endl;
	}
	List(const std::initializer_list<T>& il) :List()
	{
		for (T const* it = il.begin(); it != il.end(); ++it)
		{
			push_back(*it);
		}
	}
	List(const List<T>& other) :List()
	{
		*this = other;
		cout << "LCopyConstructor:\t" << this << endl;
	}
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
#ifdef DEBUG
		cout << "LDestructor: \t" << this << endl;
#endif // DEBUG

	}
	//					Operators:
	List<T>& operator= (const List<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
		cout << "LCopyAssignment:\t" << this << endl;
		return *this;
	}


	//					Adding Elements:
	void push_front(T Data)
	{
		if (Head == nullptr && Tail == nullptr)Head = Tail = new Element(Data);
		else Head = Head->pPrev = new Element(Data, Head);
		size++;
	}
	void push_back(T Data)
	{
		if (Head == nullptr && Tail == nullptr) Head = Tail = new Element(Data);
		else Tail = Tail->pNext = new Element(Data, nullptr, Tail);
		size++;
	}
	void insert(T Data, int Index)
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
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
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
template<typename T>List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> cat = left;
	for (typename List<T>::ConstIterator it = right.cbegin(); it != right.cend(); ++it)
	{
		//(*it) *= 10;
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

	List<int> list1 = { 3,5,8,13,21 };
	//list1.print();
	for (int i : list1)cout << i << tab; cout << endl;
	/*for (List::ReverseIterator it = list1.end(); it != list1.begin(); it--)
	{
		cout << *it << tab;
	};
	cout << endl;*/
	/*for (List::ReversIterator it = list1.rbegin(); it != list1.rend(); ++it)
	{
		cout << *it << tab;
	};
	cout << endl;*/
	for (List<int>::Iterator it = list1.begin(); it != list1.end(); ++it)
	{
		(*it) *= 10;
	}
	List<int> list2 = { 34,55,89 };
	for (int i : list2)cout << i << tab; cout << endl;

	List<int> list3 = list1 + list2;
	for (int i : list1)cout << i << tab; cout << endl;
	for (int i : list2)cout << i << tab; cout << endl;
	for (int i : list3)cout << i << tab; cout << endl;

	List<double> d_list_1 = { 2.7,3.14,5.1 };
	List<double> d_list_2 = { 4.4,8.3 };
	List<double> d_list_3 = d_list_1 + d_list_2;
	for (double i : d_list_1)cout << i << tab; cout << endl;
	for (double i : d_list_2)cout << i << tab; cout << endl;
	for (double i : d_list_3)cout << i << tab; cout << endl;
}