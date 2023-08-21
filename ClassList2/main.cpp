#include<iostream>
using namespace std;
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
	};

};

void main()
{
	setlocale(LC_ALL, "");

}