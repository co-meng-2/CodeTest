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

// 10^k 25*100^k 의 동전이 존재
// 초콜릿 가격 10^15이하
// 동전의 최소 갯수

// greedy 하게 풀어도 되는가?
// 32를 생각해보자 25(1) 1(7) / 10(3) 1(2) -> greedy 불가능
// 그렇다면 greedy 하게 풀되 25*100^k를 변형해보자
// 25 -> 10(2) 1(5) -> 32 = 10(2) 1(5) 1(7) -> 10(3) 1(2)

// 25000000000000 -> idx == 20
void dfs(long long depth, vector<long long>& coinCnt, long long& minCoinCnt, long long coinIdx = 20)
{
	// 모든 25*100^k 동전을 어떻게 바꿀지 선택 완료.
	if (depth == 7)
	{
		vector<long long> tmpCoinCnt = coinCnt;
		for (long long i = tmpCoinCnt.size() - 1; i >= 0; --i)
		{
			// 특정 동전이 10개 이상인 경우 
			if (tmpCoinCnt[i] >= 10)
			{
				// 다음 동전이 25*100^k 동전인 경우 그 다음 동전으로 건너뛴다.
				if((i - 1) % 3 == 2)
					tmpCoinCnt[i - 2] += tmpCoinCnt[i] / 10;
				else
					tmpCoinCnt[i - 1] += tmpCoinCnt[i] / 10;
				tmpCoinCnt[i] %= 10;
			}
		}

		// 모든 동전의 합을 세준다.
		long long totalCoinCnt = 0;
		for (auto cnt : tmpCoinCnt)
			totalCoinCnt += cnt;

		// 가장 작은 동전의 갯수를 기억하여 출력한다.
		minCoinCnt = std::min(minCoinCnt, totalCoinCnt);

		return;
	}

	long long curCoinCnt = coinCnt[coinIdx];
	
	// i 바꾸는 동전의 갯수 -> 25단위 동전은 최대 3개 있을 수 있다. 그 이상이면 10^k 동전으로 바뀜.
	for (int i = 0; i <= curCoinCnt; ++i)
	{
		// 현재 동전을 i개 빼고 다른 동전으로 바꿔준다.
		coinCnt[coinIdx] -= i;
		coinCnt[coinIdx + 1] += 2 * i;
		coinCnt[coinIdx + 2] += 5 * i;
		dfs(depth + 1, coinCnt, minCoinCnt, coinIdx - 3);

		// 원복한다.
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

	//	// 2, 5, 7... 25*100^k인 동전들 3k-1
	//	// dfs로 10 단위 동전으로 풀었을 때의 결과값과 비교
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