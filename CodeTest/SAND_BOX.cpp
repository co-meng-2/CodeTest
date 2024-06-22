#include <iostream>
#include <vector>
using namespace std;

class AAA
{
public:
	int a = 0;

	void func()
	{
		a++;
	}
};

int main()
{
	AAA a;
	a.func();

	string s = "1110";

	auto idx = s.find("110", 4);
	auto fidx = s.find("110");
	string t = "";
	t.append(s.begin(), s.begin() + fidx);


	return 0;
}
