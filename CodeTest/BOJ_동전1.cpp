#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// dp[x] �� x�� ���� �� �ִ� ������ ���� ��
// ������ ������ �� �� ���� ������ �� �ִ� ����� ���� ������ ���ʴ�� �Ẹ�� ���̴�.
// n�� �������� ��� x�� ���� ������ ��, n-1�� �������� ������ ��, � �� x�� ���ؼ� dp[x]�� n��° �������� �������� ���� �� �ִ� ���̹Ƿ�.
// dp[x] = dp[x] + dp[x - coin[n]] �� �����Ѵ�.

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