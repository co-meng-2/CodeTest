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

	return 0;
}
