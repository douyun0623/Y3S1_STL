//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	 5�� 8�� �����							(10�� 1��)
// 6�� 19�� ����� 15�� 2�� - �⸻����
//---------------------------------------------------------------------------
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <span>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool ����;					// �����Ϸ��� true�� ����

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

	// �Ųٷ� ����϶�.
	f(a);

	vector<int> v{ begin(a), end(a) };	// { &a[0], &a[7] };
	f(v);

	save("����.cpp");
} 