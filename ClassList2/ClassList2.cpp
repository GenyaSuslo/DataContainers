#include"ClassList2.h"

template <typename T>T& List<T>::Iterator::operator*()
{
	return ConstBaseIterator::Temp->Data;
}
template <typename T>T& List<T>::ReversIterator::operator*()
{
	return ConstBaseIterator::Temp->Data;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											List methods

template<typename T>typename List<T>::ConstIterator List<T>::cbegin()const
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::cend()const
{
	return nullptr;
}
template<typename T>typename List<T>::ConstReversIterator List<T>::crbegin()const
{
	return Tail;
}
template<typename T>typename List<T>::ConstReversIterator List<T>::crend()const
{
	return nullptr;
}
/////////////////////////////////////////////////////////////////////////////
//						Iterators methods
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
//						Iterators methods
/////////////////////////////////////////////////////////////////////////////
// 
/////////////////////////////////////////////////////////////////////////////
//						ReverseIterators methods

template<typename T>typename List<T>::ReversIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>typename List<T>::ReversIterator List<T>::rend()
{
	return nullptr;
}
//						ReverseIterators methods
/////////////////////////////////////////////////////////////////////////////



template<typename T> List<T>::List()
{
	Head = Tail = nullptr;
	cout << "LConstructor: \t" << this << endl;
}
template<typename T> List<T>::List(const std::initializer_list<T>& il) :List()
{
	for (T const* it = il.begin(); it != il.end(); ++it)
	{
		push_back(*it);
	}
}
template<typename T> List<T>::List(const List<T>& other) :List()
{
	*this = other;
	cout << "LCopyConstructor:\t" << this << endl;
}
template<typename T> List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
#ifdef DEBUG
	cout << "LDestructor: \t" << this << endl;
#endif // DEBUG

}
//					Operators:
template<typename T>List<T>& List<T>:: operator= (const List<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
	cout << "LCopyAssignment:\t" << this << endl;
	return *this;
}

//					Adding Elements:
template<typename T>void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)Head = Tail = new Element(Data);
	else Head = Head->pPrev = new Element(Data, Head);
	size++;
}
template<typename T>void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr) Head = Tail = new Element(Data);
	else Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;
}
template<typename T>void List<T>::insert(T Data, int Index)
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
template<typename T>void List<T>::pop_front()
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
template<typename T>void List<T>::pop_back()
{
	if (Head == Tail)return pop_front();
	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;
}
template<typename T>void List<T>::erase(int Index)
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
template<typename T>void List<T>::print() const
{
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
	{
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}
}
template<typename T>void List<T>::reverse_print()const
{
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
	{
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}
}

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

//											List methods
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////