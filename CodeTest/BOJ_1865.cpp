#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// N개의 지점, 지점들 사이에는 M개의 도로, W개의 웜홀
// 웜홀은 시작 위치에서 도착위치로 이동하는 경로 -> 근데 시간이 거꾸로 감
// 한 지점에서 출발 -> 다시 출발을 했던 위치로 돌아왔을 때, 시간이 되돌아가있는 경우가 있는지?

// 연결 그래프이다.
// 음의 사이클이 있다면?
// floyd로  i == j 인 경우를 보면 알 수 있지 않을까?

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