#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool check(int n, int div, int ans)
{
	if (1 + (n - 1) / div <= ans)
		return false;
	return true;
}

int main()
{
	fastio;

	int n;
	cin >> n;
	ll sum = 0;
	int ans = 1;
	int lastIdx = n;
	while(ans <= n)
	{
		int lo = 1;
		int hi = n;

		while(lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (check(n, mid, ans))
				lo = mid + 1;
			else
				hi = mid - 1;
		}

		sum += (lastIdx - lo + 1) * ans;
		lastIdx = lo - 1;

		if (lastIdx <= 100000)
		{
			for (int i = 1; i <= lastIdx; ++i)
			{
				sum += 1 + (n - 1) / i;
			}
			break;
		}

		ans++;
	}

	// 1 100 2
	cout << sum;

	return 0;
}


// S : 1002
// U : 
// T : 
// C :
// Total :