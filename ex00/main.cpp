#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	// Extra tests
	std::cout << "\n--- extra tests ---" << std::endl;

	float f1 = 4.2f;
	float f2 = -1.5f;
    std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min( f1, f2 ) = " << ::min(f1, f2) << std::endl;
	std::cout << "max( f1, f2 ) = " << ::max(f1, f2) << std::endl;

	// Equal values: must return the second argument (check by address)
	int x = 42;
	int y = 42;
    std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min returns y: " << (&::min(x, y) == &y) << std::endl;
	std::cout << "max returns y: " << (&::max(x, y) == &y) << std::endl;

	return 0;
}