export module MyGraph;

export import MyMath.Types;

export class CLine
{
public:
	CVec2 pt1;
	CVec2 pt2;

	float length() const;
};
