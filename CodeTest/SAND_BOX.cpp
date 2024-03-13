#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a = {1,2};
	vector<int> b;

	a.data	() = b.data();

	return 0;
}
