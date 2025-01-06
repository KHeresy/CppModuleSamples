export module MyMath.Compute;

import MyMath.Types;

export CVec2 operator+(const CVec2& a, const CVec2& b)
{
	return { a.x + b.x, a.y + b.y };
}
