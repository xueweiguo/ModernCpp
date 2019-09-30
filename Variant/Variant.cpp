#include <iostream>
#include <variant>

int main()
{
	union Uv {
		int i;
		double df;
	};
	Uv u1;
    u1.i = 100;
	std::cout << "u1.i=" << u1.i << std::endl;
	std::cout << "u1.df=" << u1.df << std::endl;
	u1.df = 122.0;
	std::cout << "u1.i=" << u1.i << std::endl;
	std::cout << "u1.df=" << u1.df << std::endl;

	std::variant<int, double> var{ 122.0 };
	std::cout << var.index() << std::endl;
	
	try {
		std::cout << std::get<double>(var) << std::endl;
		std::cout << std::get<int>(var) << std::endl;
	}
	catch(const std::bad_variant_access & e) {
		std::cout << e.what() << std::endl;
	}

	var = 100;
	std::cout << var.index() << std::endl;

	try {
		std::cout << std::get<int>(var) << std::endl;
		std::cout << std::get<double>(var) << std::endl;
	}
	catch (const std::bad_variant_access& e) {
		std::cout << e.what() << std::endl;
	}
}


