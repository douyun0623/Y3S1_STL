//---------------------------------------------------------------------------
// 2025 STL 화56목78	 5월 15일 목요일							(11주 1일)
// 6월 19일 목요일 15주 2일 - 기말시험
//---------------------------------------------------------------------------
// Iterator - Iterators are a generalization of pointers that 
// allow a C++ program to work with different data structures in a uniform manner. 
// 
// 반복자는 클래스로 코딩해야 합니다.
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

extern bool 관찰;					// 관찰하려면 true로 설정

template<class 반복자>
void f( 반복자 i ) 
{
	// 어떤 종류
	cout<< "반복자의 반복자 - " << typeid(반복자::iterator_category).name() << endl;
}

//--------
int main()
//--------
{
	// [문제] 반복자는 종류(6 category)가 있다. 
	// 함수 f는 반복자를 인자로 받아 어떤 종류의 반복자인지 화면에 출력하는 함수이다ㅏ.
	// 다음 코드가 문제 없이 실행되게 하자

	array<int, 2> a;
	f(a.begin());

	vector<char> v;
	f(v.end());

	f(deque<STRING>::iterator{});

	f(list<int>{}.rbegin());

	f(forward_list<int>::const_iterator{});

	f(ostream_iterator<char>{cout});

	save("메인.cpp");
} 