#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// flow
// �ִܰ�θ� ���ؾ� �ϹǷ� ��������� ����Ͽ� ���۰� ������ ���� ���� ������ ���ؼ� �ּ� ���� ����.
// �÷��̵带 ����Ͽ� ���� ����.

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	const int INF = 100'000'000;
	vector<vector<int>> adjMat(n + 1, vector<int>(n + 1,INF));

	int s, d, w;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> d >> w;
		adjMat[s][d] = std::min(adjMat[s][d],w);
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i == j) continue;
				adjMat[i][j] = std::min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <=n; ++j)
		{
			if (adjMat[i][j] == INF)
				cout << 0;
			else
				cout << adjMat[i][j];
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}



// S : 2:39
// U : 2:40 1min
// T : 2:40 0min
// C : 2:58 18min
// Total : 19min