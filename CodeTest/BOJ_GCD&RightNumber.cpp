#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

int FindKthNum()
{
	int N,K;
	cin >> N >> K;

	vector<bool> vecNum(1 + N, true);

	int cnt = 0;
	for (int i = 2; i <= N; ++i)
	{
		if (vecNum[i])
		{
			cnt++;
			if (cnt == K)
				return i;

			for (int j = i * 2; j <= N; j += i)
			{
				if (vecNum[j])
				{
					vecNum[j] = false;
					cnt++;
					if (cnt == K)
						return j;
				}
			}
		}
	}

}

int GCD(int a, int b)
{
	if (a == 0)
		return b;
	// a > b -> auto swap
	return GCD(b % a, a);
}

void SolveGCD()
{
	int a, b;
	cin >> a >> b;

	int gcd = GCD(a, b);
	cout << gcd << "\n";
	cout << a * b / gcd << "\n";
}



int main()
{
	fastio;

	// SolveGCD();
	cout << FindKthNum();

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :