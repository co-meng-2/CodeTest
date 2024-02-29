#include <iostream>
using namespace std;

int main()
{
	int chk[5]{-1, 1, 1, 1, 1};
	chk[-1] = 1;
	cout << chk[-1];

	return 0;
}
