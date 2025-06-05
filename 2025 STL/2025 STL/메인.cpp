//---------------------------------------------------------------------------
// 2025 STL ȭ56��78	 6�� 5�� �����							(13�� 2��)
// 6�� 19�� ����� 15�� 2�� - �⸻����
//---------------------------------------------------------------------------
// Unordered Associative Containers - hash ����
//---------------------------------------------------------------------------

#include <iostream>
#include <unordered_set>	
#include <print>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool ����;					// �����Ϸ��� true�� ����

template <>
struct std::hash<STRING> {
	size_t operator()(const STRING& s) const  {
		return hash<std::string> {}(string{ s.begin(), s.end() });
	}
};

//--------
int main()
//--------
{
	save("����.cpp");

	unordered_set<STRING, hash<STRING>> us{ "1", "22", "333", "4444" };
	
	for (const STRING& s : us)
		cout << s << endl;

	// ���������� �޸𸮸� ȭ�鿡 ����Ѵ�.

	while(true){
		for (size_t bc = 0; bc < us.bucket_count(); ++bc) {
			print("[{:3}] ", bc);
			for (auto i = us.begin(bc); i != us.end(bc); ++i) {
				print(" -> {:}", std::string(i->begin(), i->end()));
			}

			cout << endl;
		}
		cout << "�߰��� STRING - ";
		STRING s;
		cin >> s;

		us.insert(s);
	}
} 