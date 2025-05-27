//---------------------------------------------------------------------------
// 2025 STL 화56목78	 5월 27일 화요일							(12주 2일)
// 6월 19일 목요일 15주 2일 - 기말시험
//---------------------------------------------------------------------------
// 반복자와 알고리즘
//---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;					// 관찰하려면 true로 설정

// 강의자료 "이상한 나라의 앨리스.txt"를 다운받는다.
// [1] 여기에 있는 모든 단어를 multiset<STRING>에 저장하라.
// [2] 모두 몇 단어인지 화면에 출력하라.	- 26626


//--------
int main()
//--------
{
	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in) {
		cout << "파일?" << endl;
		return 20250527;
	}

	multiset<STRING> ms{ istream_iterator<STRING>{in}, {} };
	cout << "읽은 단어 수 - " << ms.size() << endl;		// 26626

	for (const STRING& s : ms)
		cout << s << " ";
	cout << endl;

	// 동일 단어가 몇 개 있는지 알려주자
	while (true) {
		cout << "찾을 단어? ";
		STRING 단어;
		cin >> 단어;

		cout << ms.count(단어) << "개 있습니다." << endl;
	}

	save("메인.cpp");
} 