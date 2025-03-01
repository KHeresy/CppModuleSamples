export module MyMath.IO;

export import <iostream>;
export import MyMath.Types;

export std::ostream& operator<<(std::ostream& os, const CVec2& v)
{
	return os << '(' << v.x << ',' << v.y << ')';
}
