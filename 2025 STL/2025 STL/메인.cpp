//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	 5�� 22�� �����							(12�� 1��)
// 6�� 19�� ����� 15�� 2�� - �⸻����
//---------------------------------------------------------------------------
// Associative Container - key�� ������ value�� �׻� ���Ļ��·� �����Ѵ�.
//						   ������ key���� �������� �Ѵ�.
//	set	/ mutiset	- key == value
//  map	/ multimap	- pair<key, value>
//---------------------------------------------------------------------------

#include <iostream>
#include <set>
#include <ranges>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool ����;					// �����Ϸ��� true�� ����

//  template�� specialization �Ѵ�.
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

	save("����.cpp");
} 