//---------------------------------------------------------------------------
// 2025 STL 화56목78	 5월 22일 목요일							(12주 1일)
// 6월 19일 목요일 15주 2일 - 기말시험
//---------------------------------------------------------------------------
// Associative Container - key와 연관된 value를 항상 정렬상태로 유지한다.
//						   정렬은 key값을 기준으로 한다.
//	set	/ mutiset	- key == value
//  map	/ multimap	- pair<key, value>
//---------------------------------------------------------------------------

#include <iostream>
#include <set>
#include <ranges>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;					// 관찰하려면 true로 설정

//  template을 specialization 한다.
template <>
struct std::less<STRING>{
	bool operator()(const STRING& a, const STRING& b) const
	{
		return a.size() < b.size();
	}
};

//--------
int main()
//--------
{
	class Dog{
	public:
		bool operator<(const Dog&)	const {
			return true;
		}
	};
	set<Dog> s;
	s.insert(Dog{});

	// less<Dog>
	// Dog.operator<(rhs)

	save("메인.cpp");
} 