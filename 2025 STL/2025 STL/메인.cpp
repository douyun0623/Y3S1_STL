//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	 4�� 17�� ȭ����							(7�� 2��)
// �߰����(30) - 4�� 24��(8�� 2��) ����� - ������� E�� 320
// 5�� 6�� (ȭ) -> 6�� 19��(����)
//---------------------------------------------------------------------------
// STL Container - Containers are objects that store other objects. 
// 1. SEquence Containers
//		array<T, N>
//		vector<T> - dynamic(run-time) array	
//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool ����;					// �����Ϸ��� true�� ����

// [����] vector�� ��� �޸𸮸� �����ϳ�?
// ���� �޸𸮸� ��� ������ ���

//--------
int main()
//--------
{
	���� = true;

	vector<STRING> v;

	v.emplace_back();
	v.emplace_back("���� ���ڸ� ���ڸ�");
	
	save("����.cpp");
} 