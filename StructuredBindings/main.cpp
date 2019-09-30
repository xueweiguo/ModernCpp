#include<iostream>
#include<string>

struct MyStruct {
	int i = 0;
	std::string s;
};

MyStruct getStruct() {
	return MyStruct{ 42, "hello" };
}

int BindTest()
{
	auto [r, s] = getStruct();
	std::cout << "r=" << r << ",s=" << s << std::endl;

	MyStruct ms{ 20, "Test" };
	const auto& [u, v] = ms;
	std::cout << "&u:" << &u << ",&ms:" << &ms << std::endl;

	auto& [m, n] = ms;
	std::cout << "&m:" << &m << ",&ms:" << &ms << std::endl;

	auto [i, j] = ms;
	std::cout << "&i:" << &i << ",&ms:" << &ms << std::endl;

	return 0;
}

int RFBindTest()
{
	MyStruct ms{ 20, "Test" };
	const auto&& [u, v] = std::move(ms);
	std::cout << "&u:" << &u << ",&ms:" << &ms << std::endl;
	std::cout << "v:" << v << ",ms.s:" << ms.s << std::endl;

	std::string s = std::move(v); // moves ms.s to s
	std::cout << "ms.s: " << ms.s << std::endl; // prints unspecified value
	std::cout << "v: " << v << std::endl; // prints unspecified value
	std::cout << "s: " << s << std::endl; // prints "Jim"

	return 0;
}

int main()
{
	RFBindTest();
	return 0;
}

