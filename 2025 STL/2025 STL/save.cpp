//-----------------------------------------------------------------
// save.cpp											2025�� 3�� 11��
// 
// �� �б� ���Ǹ� ���ٿ� �����ϴ� �Լ� �Դϴ�.
//-----------------------------------------------------------------


#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>

//-----------------------------
void save(std::string_view fileName)
//-----------------------------
{
	// fileName�� �б� ���� ����
	std::ifstream in{ fileName.data() };		// RAII
	if (not in) {
		std::cout << fileName << "�� �� �� �����ϴ�." << std::endl;
		exit(20250306);
	}

	// ���� ���� ������ ������ ����.
	std::string nameToSave{ "2025 1 STL ȭ56��78 ��������.txt" };
	std::ofstream out{ nameToSave, std::ios::app };

	// �����ߴٰ� ȭ�鿡 ����Ѵ�.
	auto size = std::filesystem::file_size(fileName);
	std::cout << nameToSave << "�� " << fileName << "�� ���ٿ����ϴ�. - "
		<< size << " bytes" << std::endl;

	// ������ �ð��� ���Ͽ� �������
	auto now = std::chrono::system_clock::now();			// time_point�� ��´�, epoch
	auto utc = std::chrono::system_clock::to_time_t(now);	// UTC �ð����� ����
	auto lt = std::localtime(&utc);							// �����޷½ð�����
	auto old = out.imbue(std::locale("ko_KR"));

	out << '\n' << '\n';
	out << "======================================" << '\n';
	out << "������ �ð�: " << std::put_time(lt, "%c %A") << '\n';
	out << "======================================" << '\n';
	out << '\n';

	out.imbue(old);		// ���� locale�� ����

	// ���� ���Ͽ� �ִ� ��� ������ �о� �� ���Ͽ� ���ٿ� ����
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out });
}