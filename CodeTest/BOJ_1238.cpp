#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <algorithm>
using P = std::pair<int, int>;

#include <climits>

#include <vector>
using std::vector;

#include <queue>

#include <cstring>


// N���� ������ ���� �� ���� ����� ���.
// X�� ������ ��Ƽ�� ���ֵȴ�.
// ��� X�� ������ ���ٰ� �ٽ� ������ ���ƿ´�.
// �� �� ���� ���� �ɸ��� ����� ���� ��ȣ�� ���϶�.

// �÷��̵带 ���� ���Ѵ�?
// dp[i][j] = min(dp[i][j] ,dp[i][k] + dp[k][j]);
// �ٵ� �׷��� �ð��ʰ� ���ٵ� -> 10��^3 = 10��

// ���ͽ�Ʈ��
// K -> X�� ���� ���� VElogV
// X -> K�� ���� ����� VElogV
// ���� 2���� ���ؼ� �� �� �ִ�� ���ϸ� �ȴ�.

int N; // 1 - 1000
int M; // 1 - 10000
int X;

const int INF = 100000000;

int dp[1001][1001]{};
int daikToX[1001]{};
int daikFromX[1001]{};

int main()
{
	fastio;

	cin >> N >> M >> X;

	vector<P> adjList[1001];
	for(int i = 0; i < M; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList[s].push_back({ w,d });
	}

	for(int i = 1; i <= N; ++i)
	{
		std::priority_queue<P, vector<P>, std::greater<P>> PQ;
		int table[1001]{};
		int visited[1001]{};
		std::fill(table + 1, table + N + 1, INF);
		table[i] = 0;
		PQ.push({0, i});

		while(!PQ.empty())
		{
			auto top = PQ.top();
			PQ.pop();

			if (visited[top.second]) continue;
			visited[top.second] = true;

			for (auto it : adjList[top.second])
			{
				table[it.second] = std::min(table[it.second], table[top.second] + it.first);
				PQ.push(it);
			}
		}
		if(table[X] != INF)
			daikToX[i] = table[X];
		if (i == X)
			for(int j = 1; j <=N; ++j)
				if (table[j] != INF)
					daikFromX[j] = table[j];
	}

	int Max = -1;
	for (int i = 1; i <= N; ++i)
		Max = std::max(Max, daikToX[i] + daikFromX[i]);

	cout << Max;

	// floyd
	//for(int i = 1; i <=N; ++i)
	//	std::fill(dp[i] + 1, dp[i] + N + 1, INF);

	//for(int i  = 1; i <= M; ++i)
	//{
	//	int s, d, w;
	//	cin >> s >> d >> w;
	//	dp[s][d] = w;
	//}

	//for(int k = 1; k <= N; ++k)
	//{
	//	for(int i = 1; i <= N; ++i)
	//	{
	//		for(int j = 1; j <=N; ++j)
	//		{
	//			dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
	//		}
	//	}
	//}

	//int ans = 0;
	//for (int i = 1; i <= N; ++i)
	//	for (int j = 1; j <= N; ++j)
	//	{
	//		int Max = dp[i][X] + dp[X][i];
	//		if(Max < INF)
	//			ans = std::max(ans, Max);
	//	}

	//cout << ans;

	return 0;
}