//---------------------------------------------------------------------------
// 2025 STL 화56목78	 4월 17일 화요일							(7주 2일)
// 중간고사(30) - 4월 24일(8주 2일) 목요일 - 시험장소 E동 320
// 5월 6일 (화) -> 6월 19일(예정)
//---------------------------------------------------------------------------
// STL Container - Containers are objects that store other objects. 
// 1. SEquence Containers
//		array<T, N>
//		vector<T> - dynamic(run-time) array	
//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;					// 관찰하려면 true로 설정

// [문제] vector는 어떻게 메모리를 관리하나?
// 새로 메모리를 잡는 순간만 출력

//--------
int main()
//--------
{
	관찰 = true;

	vector<STRING> v;

	v.emplace_back();
	v.emplace_back("여긴 인자만 인자만");
	
	save("메인.cpp");
} 