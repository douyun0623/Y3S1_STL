#include <iostream>
#include <random>
#include <print>
#include <array>

using namespace std;

default_random_engine dre{ random_device{}()};
default_random_engine dre2{ };
uniform_int_distribution uid{ 1,9999999 };

array<int, 20> arr;

//--------
int main()
//--------
{
	/*for (int i = 0; i < 100; ++i) {
		println("{:8}         {:8}", uid(dre), uid(dre2));
	}*/

	for (auto& a : arr) {
		a = uid(dre);
	}

	auto it = std::max_element(arr.begin(), arr.end());

	std::cout << "가장 큰 값: " << *it << '\n';
	std::cout << "해당 인덱스: " << std::distance(arr.begin(), it) << '\n';
}