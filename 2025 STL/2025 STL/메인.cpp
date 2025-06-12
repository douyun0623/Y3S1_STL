//---------------------------------------------------------------------------
// 2025 STL 화56목78	 6월 12일 목요일							(14주 2일)
// 6월 19일 목요일 15주 2일 - 기말시험, E320에서...
//---------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <list>	
#include <concepts>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;					// 관찰하려면 true로 설정

template <class Iter>
iterator_traits<Iter>::difference_type my_distance(Iter b, Iter e) 
{
	// 만약 Iter가 random_access_iterator_tag 라면
	// c++20의 concept을 이용하면 쉽다.

	//  C++17 이후에는 if-constexpt
	if constexpr (random_access_iterator<Iter>)	// Iter가 랜덤 access야?
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
	// 반복자 간의 거리를 재는 distance
	vector<int> v{ 1,2,3,4,5 };
	list<int> c{ 1,2,3,4,5 };

	cout << "vector의 distance - " << my_distance(v.end(), v.begin()) << endl;
	cout << "list의 distance -   " << my_distance(c.end(), c.begin()) << endl;

	save("메인.cpp");
} 