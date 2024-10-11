#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;

constexpr int MAX = 2000000;
int T;
ll a, b;
bool bprimes[MAX+1]{};
vector<int> primes;

int main()
{
	fastio;

	memset(bprimes, true, sizeof(bprimes));
	bprimes[0] = false;
	bprimes[1] = false;
	for(int i = 2; i <= MAX; ++i)
	{
		if (bprimes[i] == false) continue;
		primes.push_back(i);

		for(int j = 2 * i; j <= MAX; j+=i)
		{
			bprimes[j] = false;
		}
	}

	cin >> T;
	for(int i = 0; i < T; ++i)
	{
		cin >> a >> b;

		ll sum = a + b;
		if (sum <= 3) cout << "NO\n";
		else if (sum % 2 == 0) cout << "YES\n";
		else
		{
			sum -= 2;
			int mid = sqrt(sum);
			bool check = true;

			int idx = 0;
			while(idx != primes.size() && primes[idx] <= mid)
			{
				if (sum % primes[idx] == 0)
				{
					check = false;
					break;
				}
				++idx;
			}

			if (check)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	

	return 0;
}


// S : 2 54
// U : 2 56
// T : 3 05
// C : 3 10
// Total : 16min
