//---------------------------------------------------------------------------
// 2025 STL 화56목78	 5월 29일 목요일							(13주 1일)
// 6월 19일 목요일 15주 2일 - 기말시험
//---------------------------------------------------------------------------
// Associative Container - key와 연관된 value를 항상 정렬상태로 유지한다.
//						   정렬은 key값을 기준으로 한다.
//	set	/ mutiset	- key == value
//  map	/ multimap	- pair<key, value>
//---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include <format>
#include <print>
#include <map>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;					// 관찰하려면 true로 설정

// 강의자료 "이상한 나라의 앨리스.txt"를 다운받는다.
// [1] 여기에 있는 모든 단어를 multiset<STRING>에 저장하라.
// [2] 모두 몇 단어인지 화면에 출력하라.	- 26626
// [3] 단어와 사용횟수를 화면에 출력하라.

//--------
int main()
//--------
{
	save("메인.cpp");

	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in) {
		cout << "파일?" << endl;
		return 20250527;
	}

	map<STRING, size_t> wordNum;

	STRING 단어;
	while (in >> 단어)
		wordNum[단어]++;
	
	for (auto [단어, 개수] : wordNum)
		cout << 단어 << " - " << 개수 << endl;
		//println("{:20} - {:}", 단어[0], 개수);
} 