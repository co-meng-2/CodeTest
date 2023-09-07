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
// nCk���� �����ϴ� ��찡 �ִ� ��츦 ���ش�?
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