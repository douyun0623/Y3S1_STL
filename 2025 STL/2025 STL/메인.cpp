//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	 5�� 27�� ȭ����							(12�� 2��)
// 6�� 19�� ����� 15�� 2�� - �⸻����
//---------------------------------------------------------------------------
// �ݺ��ڿ� �˰���
//---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool ����;					// �����Ϸ��� true�� ����

// �����ڷ� "�̻��� ������ �ٸ���.txt"�� �ٿ�޴´�.
// [1] ���⿡ �ִ� ��� �ܾ multiset<STRING>�� �����϶�.
// [2] ��� �� �ܾ����� ȭ�鿡 ����϶�.	- 26626


//--------
int main()
//--------
{
	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (not in) {
		cout << "����?" << endl;
		return 20250527;
	}

	multiset<STRING> ms{ istream_iterator<STRING>{in}, {} };
	cout << "���� �ܾ� �� - " << ms.size() << endl;		// 26626

	for (const STRING& s : ms)
		cout << s << " ";
	cout << endl;

	// ���� �ܾ �� �� �ִ��� �˷�����
	while (true) {
		cout << "ã�� �ܾ�? ";
		STRING �ܾ�;
		cin >> �ܾ�;

		cout << ms.count(�ܾ�) << "�� �ֽ��ϴ�." << endl;
	}

	save("����.cpp");
} 