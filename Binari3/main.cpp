#include<iostream>
#include<ctime>
using namespace std;
//#define DEBUG
class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG

			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
#ifdef DEBUG

		cout << "TConstructor:\t" << this << endl;
#endif // DEBUG

	}
	Tree(const std::initializer_list<int>& il) :Tree()
	{
		for (int i : il)insert(i, Root);
	}
	~Tree()
	{
		Clear(Root);
		cout << "TDestructor:\t" << this << endl;
	}

	void insert(int Data)
	{
		insert(Data, Root);
	}
	void Clear()
	{
		Clear(Root);
		Root = nullptr;
	}
	int Depth()const
	{
		return Depth(Root);
	}
	int Sum()const
	{
		return Sum(Root);
	}
	int Count()const
	{
		return Count(Root);
	}
	int minValue()const
	{
		return minValue(Root);
	}
	int maxValue()const
	{
		return maxValue(Root);
	}
	void print()const
	{
		print(Root);
		cout << endl;
	}
	double Avg()const
	{
		return (double)Sum(Root) / Count(Root);
	}
private:
	void insert(int Data,Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
		/*insert(Data, Root->pLeft);�� �����,������ ����������� ����
		insert(Data, Root->pRight);*/
	}
	void Clear(Element* Root)
	{
		if (Root == nullptr)return;
		Clear(Root->pLeft);
		Clear(Root->pRight);
		delete Root;
	}
	int Depth(Element* Root)const
	{
		if (Root == nullptr)return 0;
		int l_depth = Depth(Root->pLeft) + 1;
		int r_depth = Depth(Root->pRight) + 1;
		return
			l_depth > r_depth?l_depth :	r_depth;
	}

	int Sum(Element* Root)const
	{
		/*if (Root == nullptr)return 0;else*/ 
			return Root==nullptr? 0 : Sum(Root->pLeft) + Sum(Root->pRight)+Root->Data;
	}
	
	int Count(Element* Root)const
	{
		return Root == nullptr ? 0 : Count(Root->pLeft)+Count(Root->pRight)+1;

	}
	
	int minValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
	}
	int maxValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
		/*if (Root->pRight == nullptr)return Root -> Data;
		else return maxValue(Root->pRight);*/
	}
	
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};
class UniqueTree:public Tree
{
	
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if(Data>Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
		/*insert(Data, Root->pLeft);�� �����,������ ����������� ����
		insert(Data, Root->pRight);*/
	}
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}

};
#define BASE_CHECK
//#define DEPTH_CHECK
void main()
{
	setlocale(LC_ALL, "");


#ifdef BASE_CHECK
	int n;
	cout << "������� ������ ������: "; cin >> n;

	Tree tree;
	clock_t start = clock();
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	clock_t end = clock();
	cout << "������ ��������� ��: " << double(end - start) / CLOCKS_PER_SEC << " ������.";
	//tree.Clear();
	//tree.print();
	cout << endl;
	cout << "����������� �������� � ������: ";
	start = clock();
	int min = tree.minValue();
	end = clock();
	cout << min << ", ��������� �� " << double(end - start) / CLOCKS_PER_SEC << " ������\n";
	////////////////////////////////////////////////////////////////////////////////////
	cout << "������������ �������� � ������: ";
	start = clock();
	int max=tree.maxValue();
	end = clock();
	cout << max << " ��������� �� " << double(end - start) / CLOCKS_PER_SEC << " ������ \n";
	////////////////////////////////////////////////////////////////////////////////////
	cout << "����� ��������� ������: \t\t";
	start = clock();
	int sum=tree.Sum();
	end = clock();
	cout << sum << "��������� �� " << double(end - start) / CLOCKS_PER_SEC << " ������\n";
	/////////////////////////////////////////////////////////////////////////////////////
	cout << "����������� ��������� ������: \t\t";
	start = clock();
	int count=tree.Count();
	end = clock();
	cout << count << "��������� �� " << double(end - start) / CLOCKS_PER_SEC << " ������\n";
	/////////////////////////////////////////////////////////////////////////////////////
	cout << "�������-�������������� ��������� ������: ";
	start = clock();
	double AVG=tree.Avg();
	end = clock();
	cout << AVG << " ��������� �� " << double(end - start) / CLOCKS_PER_SEC << " ������\n";
	////////////////////////////////////////////////////////////////////////////////////
	//tree.print();
	cout << "������� ������: ";
	start = clock();
	int depth=tree.Depth();
	end = clock();
	cout << depth << " ��������� �� " << double(end - start) / CLOCKS_PER_SEC << " ������\n";

	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100);
	}
	
	//u_tree.print();
	cout << endl;
	cout << "����������� �������� � ������: " << u_tree.minValue() << endl;
	cout << "������������ �������� � ������: " << u_tree.maxValue() << endl;
	cout << "����� ��������� ������: \t" << u_tree.Sum() << endl;
	cout << "����������� ��������� ������: \t" << u_tree.Count() << endl;
	cout << "�������-�������������� ��������� ������: " << u_tree.Avg() << endl;
	//u_tree.print();
	cout << "������� ������: " << u_tree.Depth() << endl;
#endif // BASE_CHECK
#ifdef DEPTH_CHECK

	Tree tree = { 50,25,75,16,32,64,90,28,29};
	tree.print();
	cout << "������� ������: " << tree.Depth() << endl;
#endif // DEPTH_CHECK



}