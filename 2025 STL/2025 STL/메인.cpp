//---------------------------------------------------------------------------
// 2025 STL 화56목78	 5월 20일 화요일							(11주 2일)
// 6월 19일 목요일 15주 2일 - 기말시험
//---------------------------------------------------------------------------
// 반복자와 알고리즘
//---------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;					// 관찰하려면 true로 설정

template <class 반복자,class 값>
반복자 my_find(반복자 b, 반복자 e, 값 v)
{
	while (b != e) {
		if (*b == v) {
			return b;
		}
		++b;
	}
	return b;
}

template <class 반복자, class Pred>
반복자 my_find_if(반복자 시작, 반복자 끝, Pred f) 
{
	for (; 시작 != 끝; ++시작) {
		if (f(*시작))
			return 시작;
	}
	return 끝;
}

template <class 반복자, class 목적지반복자>
void my_copy(반복자 b, 반복자 e, 목적지반복자 d) 
{
	while (b != e) {
		*d = *b;
		++b;
		++d;
	}
}

//--------
int main()
//--------
{
	STRING s{ "반복자를 사용한 알고리즘을 연습 중" };
	vector<char> v{ '1' };

	my_copy(s.begin(), s.end(), back_inserter(v));
	
	for (char c : v)
		cout << c;
	cout << endl;

	save("메인.cpp");
} 