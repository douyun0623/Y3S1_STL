//---------------------------------------------------------------------------
// 2025 STL 화56목78	 5월 8일 목요일							(10주 1일)
// 6월 19일 목요일 15주 2일 - 기말시험
//---------------------------------------------------------------------------
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <span>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;					// 관찰하려면 true로 설정

void f(span<int> s )
{
	for (auto i = s.rbegin(); i != s.rend(); ++i)
		cout << *i << " ";
	cout << endl;
}

//--------
int main()
//--------
{
	int a[]{ 1,2,3,4,5,5,6,7 };

	// 거꾸로 출력하라.
	f(a);

	vector<int> v{ begin(a), end(a) };	// { &a[0], &a[7] };
	f(v);

	save("메인.cpp");
} 