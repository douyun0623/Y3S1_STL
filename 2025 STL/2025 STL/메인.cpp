//---------------------------------------------------------------------------
// 2025 STL 화56목78	 6월 5일 목요일							(13주 2일)
// 6월 19일 목요일 15주 2일 - 기말시험
//---------------------------------------------------------------------------
// Unordered Associative Containers - hash 구조
//---------------------------------------------------------------------------

#include <iostream>
#include <unordered_set>	
#include <print>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;					// 관찰하려면 true로 설정

template <>
struct std::hash<STRING> {
	size_t operator()(const STRING& s) const  {
		return hash<std::string> {}(string{ s.begin(), s.end() });
	}
};

//--------
int main()
//--------
{
	save("메인.cpp");

	unordered_set<STRING, hash<STRING>> us{ "1", "22", "333", "4444" };
	
	for (const STRING& s : us)
		cout << s << endl;

	// 언오더드셋의 메모리를 화면에 출력한다.

	while(true){
		for (size_t bc = 0; bc < us.bucket_count(); ++bc) {
			print("[{:3}] ", bc);
			for (auto i = us.begin(bc); i != us.end(bc); ++i) {
				print(" -> {:}", std::string(i->begin(), i->end()));
			}

			cout << endl;
		}
		cout << "추가할 STRING - ";
		STRING s;
		cin >> s;

		us.insert(s);
	}
} 