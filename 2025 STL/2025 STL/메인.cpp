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
#include <algorithm>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;					// 관찰하려면 true로 설정

template<class 반복자>
void f( 반복자 i ) 
{
	cout << typeid(iterator_traits<반복자>::iterator_category).name() << endl;
	
	// 벡터는 C++20의 concept을 이용하여 contiguous임을 판정할 수 있다.
	cout << "벡터의 반복자 - " << typeid(반복자::iterator_concept).name() << endl;
}

//--------
int main()
//--------
{
	STRING s{ "2025 5 15" };

	// [문제] 문제없이 실행되게 하라.
	sort(s.begin(), s.end());

	cout << s << endl;				// "  0122555"	

	save("메인.cpp");
} 