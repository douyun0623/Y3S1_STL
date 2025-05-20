//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	 5�� 20�� ȭ����							(11�� 2��)
// 6�� 19�� ����� 15�� 2�� - �⸻����
//---------------------------------------------------------------------------
// �ݺ��ڿ� �˰���
//---------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool ����;					// �����Ϸ��� true�� ����

template <class �ݺ���,class ��>
�ݺ��� my_find(�ݺ��� b, �ݺ��� e, �� v)
{
	while (b != e) {
		if (*b == v) {
			return b;
		}
		++b;
	}
	return b;
}

template <class �ݺ���, class Pred>
�ݺ��� my_find_if(�ݺ��� ����, �ݺ��� ��, Pred f) 
{
	for (; ���� != ��; ++����) {
		if (f(*����))
			return ����;
	}
	return ��;
}

template <class �ݺ���, class �������ݺ���>
void my_copy(�ݺ��� b, �ݺ��� e, �������ݺ��� d) 
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
	STRING s{ "�ݺ��ڸ� ����� �˰����� ���� ��" };
	vector<char> v{ '1' };

	my_copy(s.begin(), s.end(), back_inserter(v));
	
	for (char c : v)
		cout << c;
	cout << endl;

	save("����.cpp");
} 