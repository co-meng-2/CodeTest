#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

// ����ȯ
// ������ �� ���� ���ÿ�������� �ʴ´�.
// N���� ������ ������ ����ȯ���� K���� ���� ���ϴ� ����� ��
// ����� ���� 10��3���� ���� �������� ���

// 1�� �� -> ?ĭ �� 1�� �� -> ?ĭ �� ....
// dfs ��Ʈ��ŷ? -> �ð� �ʰ� ����.
// ���� ���� �ȳ��´� -> dp
// dp[i][j] -> i���� ����ȯ���� j���� ĥ�ϴ� ����� ��
// i��° ĭ�� ĥ�ϴ� ���� �� ĥ�ϴ� ���� ������, ���ŵ� dp�� �̿��ؼ� �����Ѵ�.
// ������ ĭ�� dp[n][k]�� ù ��° ĭ���� ���赵 ������ �־�� �Ѵ�.

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
				dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD; // �� ĥ�ϴ� ���, ĥ�ϴ� ���
		
	if(N >= 3)
		cout << (dp[N-1][K] + dp[N-3][K-1]) % MOD; // �� ĥ�ϴ� ���, ĥ�ϴ� ���
	else
		cout << dp[N - 1][K];


	return 0;
}