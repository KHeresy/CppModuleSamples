#include <iostream>
import MyMath;

int main()
{
	CVec2 v1{ 1, 2 }, v2{ 3,4 };
	auto v3 = v1 + v2;

	std::cout << to_string(v3) << '\n'
		<< v3.length() << '\n';
}
