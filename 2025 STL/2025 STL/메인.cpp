//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	 5�� 29�� �����							(13�� 1��)
// 6�� 19�� ����� 15�� 2�� - �⸻����
//---------------------------------------------------------------------------
// Associative Container - key�� ������ value�� �׻� ���Ļ��·� �����Ѵ�.
//						   ������ key���� �������� �Ѵ�.
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

extern bool ����;					// �����Ϸ��� true�� ����

// �����ڷ� "�̻��� ������ �ٸ���.txt"�� �ٿ�޴´�.
// [1] ���⿡ �ִ� ��� �ܾ multiset<STRING>�� �����϶�.
// [2] ��� �� �ܾ����� ȭ�鿡 ����϶�.	- 26626
// [3] �ܾ�� ���Ƚ���� ȭ�鿡 ����϶�.

//--------
int main()
//--------
{
	save("����.cpp");

	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (not in) {
		cout << "����?" << endl;
		return 20250527;
	}

	map<STRING, size_t> wordNum;

	STRING �ܾ�;
	while (in >> �ܾ�)
		wordNum[�ܾ�]++;
	
	for (auto [�ܾ�, ����] : wordNum)
		cout << �ܾ� << " - " << ���� << endl;
		//println("{:20} - {:}", �ܾ�[0], ����);
} 