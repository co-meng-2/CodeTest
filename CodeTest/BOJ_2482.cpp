#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

// 색상환
// 인접한 두 색은 동시에사용하지 않는다.
// N개의 색으로 구성된 색상환에서 K개의 색을 정하는 경우의 수
// 경우의 수를 10억3으로 나눈 나머지를 출력

// 1개 고름 -> ?칸 뜀 1개 고름 -> ?칸 뜀 ....
// dfs 백트래킹? -> 시간 초과 날듯.
// 뭔가 답이 안나온다 -> dp
// dp[i][j] -> i개의 색상환에서 j개를 칠하는 경우의 수
// i번째 칸을 칠하는 경우와 안 칠하는 경우로 나누어, 갱신된 dp를 이용해서 갱신한다.
// 마지막 칸인 dp[n][k]는 첫 번째 칸과의 관계도 생각해 주어야 한다.

int N; // 1 - 1000
int K; // 1 - N

const int MOD = 1'000'000'003;

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
		for (int j = 2; j <= K; j++)
				dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD; // 안 칠하는 경우, 칠하는 경우
		
	if(N >= 3)
		cout << (dp[N-1][K] + dp[N-3][K-1]) % MOD; // 안 칠하는 경우, 칠하는 경우
	else
		cout << dp[N - 1][K];


	return 0;
}