module;
#include <string>
#include <sstream>
module MyMath:Internal;

import :Types;

std::string to_string_impl(const CVec2& v)
{
	std::ostringstream ss;
	ss << '<' << v.x << '/' << v.y << '>';
	return ss.str();
}
