#include <iostream>

import "lib2.h";
import "lib1.h";

// clang:	compile error
// g++:		100 100 100 in g++
// msvc:	10 10 10 or 100 100
int main()
{
	std::cout << getVal1() << ' ' << getVal2() << ' ';
	std::cout << getVal(); //mark this line get different value in MSVC
	std::cout << '\n';
}
