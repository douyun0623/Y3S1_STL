//------------------------------------------------------------------------------------------
// STRING.cpp - std::string�� ������ Ŭ�����̴�
//			  STL�� container�� ������ �� �ְ� �ڵ��� ������
// 
// 
//																			2025. 4. 8 ����
// 
// 
// 2025. 4. 10		�̵������� �̵�����������											
// 2025. 5. 8		operator <
// 2025. 5. 13		begin(), end()
//-----------------------------------------------------------------------------------------

#include <print>
#include <algorithm>
#include <string>
#include "STRING.h"

bool ����{ false };												// 2025. 04. 08
	
STRING::STRING()												// 2025. 04. 08 ���� ������ ���� �ڵ�
	: id {++gid}
{
	if (����) {
		std::println("[{:8}] {:16} �ڿ���:{:<10} �޸�:{:<12}, �ڿ��޸�:{:<12}",
			id, "����Ʈ����", len, (void*)this, (void*)p.get());
	}
}

STRING::~STRING()												// 2025. 04. 08
{
	if (����) {
		std::println("[{:8}] {:16} �ڿ���:{:<10} �޸�:{:<12}, �ڿ��޸�:{:<12}",
			id, "�Ҹ���", len, (void*)this, (void*)p.get());
	}
}

STRING::STRING(const char* s) 
	: id{++gid}, len{ strlen(s) }
{
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);		

	if (����) {
		std::println("[{:8}] {:16} �ڿ���:{:<10} �޸�:{:<12}, �ڿ��޸�:{:<12}",
			id, "������(char*)", len, (void*)this, (void*)p.get());
	}
}

// ���� ������
STRING::STRING(const STRING& other)								// 2025. 04. 08
	: id{ ++gid }, len{ other.len }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (����) {
		std::println("[{:8}] {:16} �ڿ���:{:<10} �޸�:{:<12}, �ڿ��޸�:{:<12}",
			id, "���������", len, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(const STRING& other)					// 2025. 04. 08
{
	if (this == &other)
		return *this;

	len = other.len;
	p.release();				// p.reset()�� �ٸ� ���� ��������
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (����) {
		std::println("[{:8}] {:16} �ڿ���:{:<10} �޸�:{:<12}, �ڿ��޸�:{:<12}",
			id, "�����Ҵ翬����", len, (void*)this, (void*)p.get());
	}

	return *this;
}

STRING::STRING(STRING&& other)
	: id{ ++gid }, len{ other.len }
{
	p.reset(other.p.release());
	other.len = 0;

	if (����) {
		std::println("[{:8}] {:16} �ڿ���:{:<10} �޸�:{:<12}, �ڿ��޸�:{:<12}",
			id, "�̵�������", len, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(STRING&& other)
{
	if (this == &other) {
		return *this;
	}

	len = other.len;

	p.release();
	p.reset(other.p.release());

	other.len = 0;

	if (����) {
		std::println("[{:8}] {:16} �ڿ���:{:<10} �޸�:{:<12}, �ڿ��޸�:{:<12}",
			id, "�̵��Ҵ翬����", len, (void*)this, (void*)p.get());
	}

	return*this;
}

// ���� �����ڵ�
//bool STRING::operator==(const STRING& rhs) const
//{
//	return std::equal(&p[0], &p[len], &rhs.p[0], &rhs.p[rhs.len]);
//}
//
bool STRING::operator<(const STRING& rhs) const					// 2025. 5 . 8
{
	return std::lexicographical_compare(p.get(), p.get() + len,
		rhs.p.get(), rhs.p.get() + rhs.len);
}

// 2025. 5. 22
// ��� ���迬���ڸ� ��ü�ϴ� three-way comparison operator
//auto STRING::operator<=>(const STRING& rhs) const
//{
//}

size_t STRING::size() const
{
	return len;
}

// begin(), end()
STRING_Iterator STRING::begin() const
{
	return p.get();			// return &p[0]
}

STRING_Iterator STRING::end() const
{
	return p.get() + len;	// return &p[len]
}

STRING_Reverse_Iterator STRING::rbegin() const
{
	return STRING_Reverse_Iterator{ p.get() + len };
}

STRING_Reverse_Iterator STRING::rend() const
{
	return STRING_Reverse_Iterator{ p.get() };
}

std::ostream& operator<<(std::ostream& os, const STRING& str) {
	for (int i = 0; i < str.len; ++i)
		os << str.p[i];
	return os;
}

std::istream& operator>>(std::istream& is, STRING& str)
{
	std::string s;
	is >> s;
	str.len = s.length();
	str.p.release();
	str.p = std::make_unique<char[]>(str.len);
	memccpy((char*)str.p.get(), s.data(), '\0', str.len);
	return is;
}

size_t STRING::gid{ };								// 2025. 04. 08