#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

// 생상환
// 인접한 두 색은 동시에사용하지 않는다.
// N개의 색으로 구성된 색상환에서 K개의 색을 정하는 경우의 수
// 경우의 수를 10억3으로 나눈 나머지를 출력

// 1개 고름 -> ?칸 뜀 1개 고름 -> ?칸 뜀 ....
// dfs 백트래킹? -> 시간 초과 날듯.
// nCk에서 인접하는 경우가 있는 경우를 빼준다?
// 


int N; // 1 - 1000
int K; // 1 - N

const int MOD = 100'000'003;

int dp[1001][1001]{};
int ans;

int main()
{
	cin >> N >> K;

	for (int i = 0; i <= N; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
		{
			if (i == N && j == K)
				dp[i][j] = dp[i - 1][j] + dp[i - 3][j - 1];
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 2][j - 1];
		}
	}
		
	cout << dp[N][K];


	return 0;
}