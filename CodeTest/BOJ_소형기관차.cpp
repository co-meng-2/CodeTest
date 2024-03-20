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

int n, len;
int train[50001]{};
int acc[50001]{};
int dp[4][50001]{};

// dp[i][j] i개의 렉카를 쓰고, j까지의 객차를 운송 할 수 있을 때, 운송 가능한 승객의 최댓값.
// 서로 독립된 경우를 만드는 것이 중요한데, 여기서는 렉카를 한 개 뺐을때와 비교해서 이런 경우를 만든다.
// dp[i-1][j-len] + [j-len+1 ~ j 까지의 객차 승객의 합]으로 dp[i][j-1]과 비교해서 j까지의 최대 승객을 알 수 있다.
// dp[towTruck][trainIdx] = max(dp[towTruck - 1][trainIdx - len] + acc[trainIdx] - acc[trainIdx - len], dp[towTruck][trainIdx-1]);

int main()
{
	fastio;

	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> train[i];
		acc[i] = acc[i-1] + train[i];
	}
	cin >> len;
	

	for(int towTruck = 1; towTruck <=3; towTruck++)
	{
		for (int trainIdx = towTruck * len; trainIdx <= n; trainIdx++)
		{
			int add = acc[trainIdx] - acc[trainIdx - len];
			dp[towTruck][trainIdx] = max(dp[towTruck - 1][trainIdx - len] + add, dp[towTruck][trainIdx-1]);
		}
	}

	cout << dp[3][n];
	

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :