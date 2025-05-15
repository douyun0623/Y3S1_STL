//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	 5�� 15�� �����							(11�� 1��)
// 6�� 19�� ����� 15�� 2�� - �⸻����
//---------------------------------------------------------------------------
// Iterator - Iterators are a generalization of pointers that 
// allow a C++ program to work with different data structures in a uniform manner. 
// 
// �ݺ��ڴ� Ŭ������ �ڵ��ؾ� �մϴ�.
//---------------------------------------------------------------------------

#include <iostream>
#include <iterator>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool ����;					// �����Ϸ��� true�� ����

template<class �ݺ���>
void f( �ݺ��� i ) 
{
	// � ����
	cout<< "�ݺ����� �ݺ��� - " << typeid(�ݺ���::iterator_category).name() << endl;
}

//--------
int main()
//--------
{
	// [����] �ݺ��ڴ� ����(6 category)�� �ִ�. 
	// �Լ� f�� �ݺ��ڸ� ���ڷ� �޾� � ������ �ݺ������� ȭ�鿡 ����ϴ� �Լ��̴٤�.
	// ���� �ڵ尡 ���� ���� ����ǰ� ����

	array<int, 2> a;
	f(a.begin());

	vector<char> v;
	f(v.end());

	f(deque<STRING>::iterator{});

	f(list<int>{}.rbegin());

	f(forward_list<int>::const_iterator{});

	f(ostream_iterator<char>{cout});

	save("����.cpp");
} 