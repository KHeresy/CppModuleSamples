module;
#include <string>
export module MyMath;

export import :Types;
export import :Compute;

import :Internal;

export std::string to_string(const CVec2& v)
{
	return to_string_impl(v);
}