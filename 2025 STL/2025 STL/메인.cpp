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
#include <algorithm>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool ����;					// �����Ϸ��� true�� ����

template<class �ݺ���>
void f( �ݺ��� i ) 
{
	cout << typeid(iterator_traits<�ݺ���>::iterator_category).name() << endl;
	
	// ���ʹ� C++20�� concept�� �̿��Ͽ� contiguous���� ������ �� �ִ�.
	cout << "������ �ݺ��� - " << typeid(�ݺ���::iterator_concept).name() << endl;
}

//--------
int main()
//--------
{
	STRING s{ "2025 5 15" };

	// [����] �������� ����ǰ� �϶�.
	sort(s.begin(), s.end());

	cout << s << endl;				// "  0122555"	

	save("����.cpp");
} 