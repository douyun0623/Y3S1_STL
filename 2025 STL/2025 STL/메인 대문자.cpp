//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	3�� 11�� ȭ����								(4�� 1��)
//---------------------------------------------------------------------------
// ���� ���� �ڷ� - FILE
//---------------------------------------------------------------------------

#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"
USING NAMESPACE STD;

// [����] "����.CPP"�� ���� �߿� �ҹ��ڸ� ��� �빮�ڷ� �ٲ� "���� �빮��.CPP"�� �����϶�.

//--------
INT MAIN()
//--------
{
	IFSTREAM IN{ "����.CPP" };
	IF (NOT IN)
		RETURN 20250325;

	OFSTREAM OUT{ "���� �빮��.CPP" };
	
	TRANSFORM(ISTREAMBUF_ITERATOR<CHAR>{IN}, {},
		OSTREAMBUF_ITERATOR<CHAR>{OUT},
		[](CHAR C) {RETURN TOUPPER(C);});

	SAVE("����.CPP");
}