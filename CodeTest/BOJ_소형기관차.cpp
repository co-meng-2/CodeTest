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


	// 1 or n번째 칸으로부터 i번째 칸 까지의 최대 사람 수 
	vector<int> dp_front(n + 1);
	vector<int> dp_back(n + 1);
	for(int i = len; i <= n; ++i)
	{
		dp_front[i] = max(dp_front[i - 1], acc[i] - acc[i - len]);
	}

	for(int i = n-len + 1; i >= 1; --i)
	{
		dp_back[i] = max(dp_back[i + 1], acc[i + len - 1] - acc[i-1]);
	}

	// 10 2 7
	int Max = -1;
	for(int i = len + 1; i <= n - len*2 + 1; ++i)
	{
		int secondCur = acc[i + len -1] - acc[i - 1];
		// 1 ~ i-1까지
		dp_front[i - 1];

		// i + len ~ n까지
		dp_back[i + len];

		Max = max(Max, dp_front[i - 1] + secondCur + dp_back[i + len]);
	}

	cout << Max;



	// dp
	//for(int towTruck = 1; towTruck <=3; towTruck++)
	//{
	//	for (int trainIdx = towTruck * len; trainIdx <= n; trainIdx++)
	//	{
	//		int add = acc[trainIdx] - acc[trainIdx - len];
	//		dp[towTruck][trainIdx] = max(dp[towTruck - 1][trainIdx - len] + add, dp[towTruck][trainIdx-1]);
	//	}
	//}

	//cout << dp[3][n];
	

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :