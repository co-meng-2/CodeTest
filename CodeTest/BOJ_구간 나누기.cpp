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
#include <unordered_set>
#include <set>
#include <string>
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;
const int MINF = 0xc0c0c0c0;

// M개의 구간으로 나누는 것은 M -1개를 빼면된다.
// 1. 가장 작은 숫자를 뺀다.
// 2. 구간이 M개 인지 확인.
// 2-1. 아니라면 1로
// 2-2. 맞다면 끝

// 이미 뺀 구간 양 옆일 경우. -> 구간이 늘어나지 않는다.
// 음수는 뺄 수록 좋다.
// 양수는 안 빼야 한다.
// ------------------------------------------------------- greedy -> 반례가 너무 많다...
// DP로 풀어야 함

int n, m;

// 사용 O or X | x번째 숫자 까지 | 구간의 갯수
int dp[2][100][51]{};

int main()
{
	fastio;
	cin >> n >> m;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> nums[i];
	}

	memset(dp, 0xc0, sizeof(dp)); // 음수 값이 포함되므로 -1로 초기화하면 안댐.

	dp[0][0][0] = 0;
	dp[1][0][1] = nums[0];

	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j <= m; ++j)
		{
			dp[0][i][j] = max(dp[0][i - 1][j], dp[1][i - 1][j]);
			if (j == 0)
				dp[1][i][j] = dp[1][i - 1][j] + nums[i];
			else
				dp[1][i][j] = max( dp[0][i - 1][j - 1] + nums[i], dp[1][i - 1][j] + nums[i] );
		}
	}

	cout << max(dp[0][n - 1][m], dp[1][n-1][m]);

	return 0;
}


// S : 5 15
// U : 5 15
// T : 6 20
// C : 6 54
// Total : 1h 40m

// Comment
// 구간 -> 누적합, sweeping에 너무 매몰되어 있었다...
// DP를 쓰는 것이라니!!!.
// 게다가 문제가 너무 greedy하게 풀릴것처럼 해놓음ㅋㅋ;