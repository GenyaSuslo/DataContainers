#include"ClassList2.h"
#include<iostream>
using namespace std;
#define tab "\t"
#define delimeter "\n----------------------------------------------------------\n"


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