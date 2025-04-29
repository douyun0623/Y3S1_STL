//------------------------------------------------------------------------------------------
// STRING.h - std::string�� ������ Ŭ�����̴�
//			  STL�� container�� ������ �� �ְ� �ڵ��� ������
// 
// 
//																			2025. 4. 8 ����
//------------------------------------------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>

class STRING {
public:
	STRING();											// 2025. 04. 08
	~STRING();											// 2025. 04. 08
														// ������ ���� ��¿ �� ����

	STRING(const char* s);

	// ��������� �����Ҵ翬����
	STRING(const STRING& str);							// 2025. 04. 08
	STRING& operator=(const STRING&);					// 2025. 04. 08

	// �̵������� �̵��Ҵ翬����						// 2025. 04. 10
	STRING(STRING&&);									// && -> rvalue reference
	STRING& operator=(STRING&&);

	// �������̽� �Լ���
	size_t size() const;

private:
	size_t len{};
	std::unique_ptr<char[]> p{};
	size_t id;											// 2025. 04. 08

	friend std::ostream& operator<<(std::ostream& os, const STRING& str);

	static size_t gid;									// 2025. 04. 08
};
