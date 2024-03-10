#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <queue>
// 두 개로 나누는 방법의 가짓수
// 각 가짓수에 대한 차의 최솟값

// 시그마 10Cn n -> 1 ~ n/2
// 최대 10 9 8 7 5 / 5 4 3 2 1 = 105
// 그냥 brute force!

using pii = std::pair<int, int>;

bool IsConnected(int sIdx, int n, vector<vector<int>>& adjList, vector<pii>& popul, int cnt, int color)
{
	vector<int> visited(n + 1);
	std::queue<int> Q;
	Q.push(sIdx);
	int total = 0;
	while (!Q.empty())
	{
		auto front = Q.front();
		Q.pop();

		if (visited[front]) continue;
		visited[front] = true;
		total++;

		for (auto d : adjList[front])
		{
			if (popul[d].second != color) continue;
			Q.push(d);
		}
	}

	if (total == cnt) return true;
	return false;
}

int main()
{
	fastio;

	int n;
	cin >> n;

	vector<pii> popul(n + 1);
	for(int i = 1; i <=n; ++i)
	{
		cin >> popul[i].first;
		popul[i].second = 0;
	}

	vector<vector<int>> adjList(n + 1);
	for(int i = 1; i <=n ;++i)
	{
		int adjcnt;
		cin >> adjcnt;
		for(int j = 0;j < adjcnt; ++j)
		{
			int adj;
			cin >> adj;
			adjList[i].push_back(adj);
		}
	}

	const int INF = 100000000;
	int min = INF;
	for(int cnt = 1; cnt <= n/2; ++cnt)
	{
		vector<int> permu;
		for (int i = 1; i <= n-cnt; i++)
			permu.push_back(0);
		for (int i = 1; i <= cnt; ++i)
			permu.push_back(1);

		do
		{
			// 색칠하기
			vector<pii> populcopy = popul;
			int sIdxRed = -1;
			int sIdxBlue = -1;
			for(int i = 0; i < permu.size(); ++i)
			{
				if (permu[i] == 1)
				{
					populcopy[i + 1].second = 1;
					sIdxRed = i + 1;
				}
				else
					sIdxBlue = i + 1;
			}

			bool bRed = IsConnected(sIdxRed, n, adjList, populcopy, cnt, 1);
			bool bBlue = IsConnected(sIdxBlue, n, adjList, populcopy, n-cnt, 0);

			if (!bRed || !bBlue) continue;

			int totalRed = 0;
			int totalBlue = 0;
			for (int i = 0; i < permu.size(); ++i)
			{
				if (permu[i] == 1)
					totalRed += popul[i + 1].first;
				else
					totalBlue += popul[i + 1].first;
			}
			min = std::min(min, std::abs(totalRed - totalBlue));

		} while (std::next_permutation(permu.begin(), permu.end()));
	}

	// bitmask로도 2개의 그룹으로 나눌 수 있다.
	// vector<int> vecRed;
	// vector<int> vecBlue;
	// for(int i = 1; i < (1 << n) -1; ++i)
	// {
	// 	for(int j = 1; j <= n; ++j)
	// 	{
	// 		if (i & (1 << (j - 1))) vecRed.push_back(j);
	// 		else vecBlue.push_back(j);
	// 	}
	// }

	if (min == INF)
		cout << -1;
	else
		cout << min;

	return 0;
}


// S : 9:20
// U : 9:21
// T : 9:27
// C : 10:03
// Total : 43min