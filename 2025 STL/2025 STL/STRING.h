//------------------------------------------------------------------------------------------
// STRING.h - std::string�� ������ Ŭ�����̴�
//			  STL�� container�� ������ �� �ְ� �ڵ��� ������
// 
// 
//																			2025. 4. 8 ����
// >> ������																	2025. 5. 1
// > ������																	2025. 5. 8		
// begin(), end()															2025. 5. 13
// ������ �ݺ��ڴ� �ݵ�� Ŭ������ ����										2025. 5. 13
// �ݺ��ڵ� �翬�� Ŭ������ �ڵ��ؾ� ��										2025. 5. 15
//------------------------------------------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>

class STRING_Iterator {
	//  ǥ�� �ݺ��ڴ� ���� �ټ����� ������ ����� �� �־�� �Ѵ�.
public:
	using difference_type = ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

public:
	STRING_Iterator(char* p) : p{p}{}

	//  �ݺ��ڶ�� �ּ��� ���� ����� �����ؾ� ��
	char operator*() const {
		return *p;
	}

	char* operator++() {
		return ++p;
	}

	bool operator==(const STRING_Iterator& rhs) const {
		return p == rhs.p;
	}

private:
	char* p;
};

// �ݺ��� �����
class STRING_Reverse_Iterator {
public:
	STRING_Reverse_Iterator(char* p) : p{ p } {}

	char operator*() const {
		return *(p - 1);
	}
	void operator++() {
		--p;
	}
	bool operator==(const STRING_Reverse_Iterator& rhs) const {
		return p == rhs.p;
	}
private:
	char* p;
};

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

	// 2024. 04. 22 ���迬���ڵ�
	bool operator==(const STRING& rhs) const;
	bool operator<(const STRING& rhs)const;				// 2025. 5. 8

	// �������̽� �Լ���
	size_t size() const;

	// begin(), end()
	STRING_Iterator begin() const;
	STRING_Iterator end()	const;

	STRING_Reverse_Iterator rbegin() const;
	STRING_Reverse_Iterator rend() const;

private:
	size_t len{};
	std::unique_ptr<char[]> p{};
	size_t id;											// 2025. 04. 08

	friend std::ostream& operator<<(std::ostream& os, const STRING& str);
	// 2025. 5. 1 
	friend std::istream& operator>>(std::istream& is, STRING& str);

	static size_t gid;									// 2025. 04. 08
};
