module;
#include <cmath>
module MyMath;

float CVec2::length() const
{
	return std::sqrt(x * x + y * y);
}
