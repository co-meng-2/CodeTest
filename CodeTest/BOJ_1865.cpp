#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// N���� ����, ������ ���̿��� M���� ����, W���� ��Ȧ
// ��Ȧ�� ���� ��ġ���� ������ġ�� �̵��ϴ� ��� -> �ٵ� �ð��� �Ųٷ� ��
// �� �������� ��� -> �ٽ� ����� �ߴ� ��ġ�� ���ƿ��� ��, �ð��� �ǵ��ư��ִ� ��찡 �ִ���?

// ���� �׷����̴�.
// ���� ����Ŭ�� �ִٸ�?
// floyd��  i == j �� ��츦 ���� �� �� ���� ������?

int T;
int N, M, W; // 1- 500, 2500, 200
const int INF = 10001;
int floyd[501][501]{};

int main()
{
	cin >> T;

	for(int TC = 0; TC < T; ++TC)
	{
		cin >> N >> M >> W;

		for(int i = 1; i <= N; ++i)
			std::fill(floyd[i] + 1, floyd[i] + N + 1, INF);

		int s, e, t;
		for (int i = 0; i < M; ++i)
		{
			cin >> s >> e >> t;
			floyd[s][e] = std::min(t, floyd[s][e]);
			floyd[e][s] = std::min(t, floyd[e][s]);
		}

		for (int i = 0; i < W; ++i)
		{
			cin >> s >> e >> t;
			floyd[s][e] = std::min(-t, floyd[s][e]);
		}

		bool flag = false;
		for(int k = 1; k <= N; ++k)
			for (int i = 1; i <= N; ++i)
				for (int j = 1; j <= N; ++j)
				{
					floyd[i][j] = std::min(floyd[i][j], floyd[i][k] + floyd[k][j]);
					if(i == j && floyd[i][i] < 0)
					{
						j = N;
						i = N;
						k = N;
						flag = true;
					}
				}
		if(flag)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}