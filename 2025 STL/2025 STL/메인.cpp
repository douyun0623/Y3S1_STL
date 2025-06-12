//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	 6�� 12�� �����							(14�� 2��)
// 6�� 19�� ����� 15�� 2�� - �⸻����, E320����...
//---------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <list>	
#include <concepts>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool ����;					// �����Ϸ��� true�� ����

template <class Iter>
iterator_traits<Iter>::difference_type my_distance(Iter b, Iter e) 
{
	// ���� Iter�� random_access_iterator_tag ���
	// c++20�� concept�� �̿��ϸ� ����.

	//  C++17 ���Ŀ��� if-constexpt
	if constexpr (random_access_iterator<Iter>)	// Iter�� ���� access��?
		return e - b;
	else {
		typename iterator_traits<Iter>::difference_type d{};
		while (b != e) {
			++b;
			++d;
		}
		return d;
	}
}

//--------
int main()
//--------
{
	// �ݺ��� ���� �Ÿ��� ��� distance
	vector<int> v{ 1,2,3,4,5 };
	list<int> c{ 1,2,3,4,5 };

	cout << "vector�� distance - " << my_distance(v.end(), v.begin()) << endl;
	cout << "list�� distance -   " << my_distance(c.end(), c.begin()) << endl;

	save("����.cpp");
} 