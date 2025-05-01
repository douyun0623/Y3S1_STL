//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	 4�� 229�� ȭ����							(9�� 1��)
// 5�� 6�� (ȭ) -> 6�� 19��(����)
//---------------------------------------------------------------------------
// STL Container - Containers are objects that store other objects. 
// 1. SEquence Containers
//		array<T, N>
//		vector<T> - push_back() O(1)
//		deque<T> - push_front()/push_back() O(1)
//		list<T> - node ���, ������ ��ġ���� ���԰� ���� O(1)
//---------------------------------------------------------------------------
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool ����;					// �����Ϸ��� true�� ����


//--------
int main()
//--------
{
	// [����] "����.cpp"�� �ܾ list�� �����϶�.
	// ã�� �ܾ ������� ������ ����. ������ list�� �� ��° �ܾ����� ����� ����.

	ifstream in{ "����.cpp" };
	if (not in)
		return 20250501;

	list<STRING> �ܾ��{ istream_iterator<STRING>{in}, {} };

	while (true) {
		cout << "ã���� �ܾ�? ";
		STRING �ܾ�;
		cin >> �ܾ�;
		
		auto res = find(�ܾ��.begin(), �ܾ��.end(), �ܾ�);
		if (res == �ܾ��.end())
			cout << �ܾ� << " - ���� �ܾ��Դϴ�. " << endl;
		else
			cout << "ã�ҽ��ϴ� " << endl;
	}

	save("����.cpp");
} 