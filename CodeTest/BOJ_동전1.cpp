#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// dp[x] 합 x를 만들 수 있는 동전의 조합 수
// 조합을 따져야 할 때 쉽게 생각할 수 있는 방법은 동전 종류를 차례대로 써보는 것이다.
// n번 동전으로 모든 x에 대해 갱신한 후, n-1번 동전으로 갱신할 때, 어떤 합 x에 대해서 dp[x]는 n번째 동전들의 조합으로 만들 수 있는 합이므로.
// dp[x] = dp[x] + dp[x - coin[n]] 이 성립한다.

int main()
{
	fastio;

	int n, k;
	cin >> n >> k;

	vector<int> coins;
	for (int i = 0; i < n; ++i)
	{
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}

	vector<int> dp(k + 1);
	dp[0] = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = coins[i]; j <= k; ++j)
		{
			dp[j] += dp[j - coins[i]];
		}
	}
	
	cout << dp[k];

	return 0;
}


// S : 12:14
// U : 12:15
// T : FAILED
// C : 
// Total :