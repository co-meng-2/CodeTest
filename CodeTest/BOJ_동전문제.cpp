#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <climits>
#include <cmath>

// 10^k 25*100^k �� ������ ����
// ���ݸ� ���� 10^15����
// ������ �ּ� ����

// greedy �ϰ� Ǯ� �Ǵ°�?
// 32�� �����غ��� 25(1) 1(7) / 10(3) 1(2) -> greedy �Ұ���
// �׷��ٸ� greedy �ϰ� Ǯ�� 25*100^k�� �����غ���
// 25 -> 10(2) 1(5) -> 32 = 10(2) 1(5) 1(7) -> 10(3) 1(2)

// 25000000000000 -> idx == 20
void dfs(long long depth, vector<long long>& coinCnt, long long& minCoinCnt, long long coinIdx = 20)
{
	// ��� 25*100^k ������ ��� �ٲ��� ���� �Ϸ�.
	if (depth == 7)
	{
		vector<long long> tmpCoinCnt = coinCnt;
		for (long long i = tmpCoinCnt.size() - 1; i >= 0; --i)
		{
			// Ư�� ������ 10�� �̻��� ��� 
			if (tmpCoinCnt[i] >= 10)
			{
				// ���� ������ 25*100^k ������ ��� �� ���� �������� �ǳʶڴ�.
				if((i - 1) % 3 == 2)
					tmpCoinCnt[i - 2] += tmpCoinCnt[i] / 10;
				else
					tmpCoinCnt[i - 1] += tmpCoinCnt[i] / 10;
				tmpCoinCnt[i] %= 10;
			}
		}

		// ��� ������ ���� ���ش�.
		long long totalCoinCnt = 0;
		for (auto cnt : tmpCoinCnt)
			totalCoinCnt += cnt;

		// ���� ���� ������ ������ ����Ͽ� ����Ѵ�.
		minCoinCnt = std::min(minCoinCnt, totalCoinCnt);

		return;
	}

	long long curCoinCnt = coinCnt[coinIdx];
	
	// i �ٲٴ� ������ ���� -> 25���� ������ �ִ� 3�� ���� �� �ִ�. �� �̻��̸� 10^k �������� �ٲ�.
	for (int i = 0; i <= curCoinCnt; ++i)
	{
		// ���� ������ i�� ���� �ٸ� �������� �ٲ��ش�.
		coinCnt[coinIdx] -= i;
		coinCnt[coinIdx + 1] += 2 * i;
		coinCnt[coinIdx + 2] += 5 * i;
		dfs(depth + 1, coinCnt, minCoinCnt, coinIdx - 3);

		// �����Ѵ�.
		coinCnt[coinIdx] += i;
		coinCnt[coinIdx + 1] -= 2 * i;
		coinCnt[coinIdx + 2] -= 5 * i;
	}
}

int main()
{
	fastio;

	int T;
	cin >> T;

	//while(T--)
	//{
	//	long long cost;
	//	cin >> cost;

	//	vector<long long> coins;

	//	long long maxCost = pow(10, 15);
	//	int i = 0;
	//	while (pow(10, i) <= maxCost)
	//	{
	//		coins.push_back(pow(10, i));
	//		i++;
	//	}

	//	i = 0;
	//	while (25LL * pow(100, i) <= maxCost)
	//	{
	//		coins.push_back(25LL * pow(100, i));
	//		i++;
	//	}

	//	std::sort(coins.begin(), coins.end(), std::greater<long long>());

	//	vector<long long> coinCnt(coins.size());

	//	long long idx = 0;
	//	long long totalCoinCnt = 0;
	//	while (cost != 0)
	//	{
	//		if (cost / coins[idx])
	//		{
	//			coinCnt[idx] = cost / coins[idx];
	//			totalCoinCnt += coinCnt[idx];
	//			cost -= coins[idx] * (cost / coins[idx]);
	//		}
	//		idx++;
	//	}

	//	// 2, 5, 7... 25*100^k�� ������ 3k-1
	//	// dfs�� 10 ���� �������� Ǯ���� ���� ������� ��
	//	long long minCoinCnt = 1000000000;
	//	dfs(0, coinCnt, minCoinCnt);
	//	cout << minCoinCnt << "\n";
	//}

	while (T--)
	{
		int dp[100]{};
		std::fill(dp, dp + 100, INT_MAX);
		long long cost;
		cin >> cost;

		dp[0] = 0;
		for (int i = 1; i < 100; ++i)
		{
			dp[i] = std::min(dp[i - 1] + 1, dp[i]);
			if(i >= 10)
				dp[i] = std::min(dp[i - 10] + 1, dp[i]);
			if(i >= 25)
				dp[i] = std::min(dp[i - 25] + 1, dp[i]);
		}

		int ans = 0;
		while (cost)
		{
			long long curNum = cost % 100;
			ans += dp[curNum];
			cost /= 100;
		}

		cout << ans << "\n";
	}

	return 0;
}


// S : 9:53
// U : 9:55
// T : 10:08
// C : 12:00
// Total : 127