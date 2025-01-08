export module MyMath.Compute;

export import MyMath.Types;
import <cmath>;

export CVec2 operator+(const CVec2& a, const CVec2& b)
{
	return { a.x + b.x, a.y + b.y };
}

export CVec2 operator-(const CVec2& a, const CVec2& b)
{
	return { a.x - b.x, a.y - b.y };
}

export float length(const CVec2& v)
{
	return std::sqrt(v.x * v.x + v.y * v.y);
}
