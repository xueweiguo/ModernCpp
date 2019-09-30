#include<vector>
#include<iostream>
#include<algorithm>
#include<gsl>

using index = std::ptrdiff_t;

int main()
{
	std::vector<int> v{ 1,2,3,4,5,6 };
	gsl::index i = 0;
	while (i < v.size()) {
		std::cout << v[i] << std::endl;
		++i;
	}

	for (const auto& x : v) {
		std::cout << x << std::endl;
	}

	std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << std::endl; });
}





