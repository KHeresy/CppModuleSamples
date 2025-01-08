import <iostream>;
import MyMath.IO;
import MyGraph;

int main()
{
	CVec2 v1{ 1,2 }, v2{ 1,3 };
	CLine m{ v1, v2 };
	std::cout << "length of {" << m.pt1 << " - " << m.pt2 << "} is " << m.length() << '\n';
}
