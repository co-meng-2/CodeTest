#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)

using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <algorithm>
#include <cstring>


// 일부 사건들의 전 후 관계가 주어졌을 때, 모든 사건들의 전후관계를 알 수 있을까?

// n 알고 있는 사건의 전후 관계의 수 1- 400
// k 전후 관계를 알고 있는 두 사건의 번호
// 앞의 번호가 뒤의 번호의 사건보다 먼저 일어났음
// s 사건의 전후 관계를 알 고 싶은 사건 쌍의 수 1-50'000

// 문제
// s줄에 걸쳐 물음에 답한다. 앞의 번호 사건이 먼저 일어났으면 -1, 뒤의 번호가 1, 모르면 0

// 어떤 자료구조를 만들어야 할 듯?
// 1 > 2  2 > 3
// 자기보다 작은 사건을 벡터로 들고 있고, 계속 더 작은 사건으로 탐색하면 되지 않을까?
// 근데 그러면 1 > 2 2 > 3 1 > 3 1 > 4 2 > 4 3 > 4 이런 경우에 O(n^2) 가능
// bfs로 visited check하며 탐색
// 이렇게 해도 같은 경로에 대한 검색이 계속 중복 될 것.
// 플로이드를 써야 한다.

int N, K, S;

vector<int> cases[401]{};
bool visited[401]{};
bool floyd[401][401]{};

int main()
{
	fastio;

	cin >> N >> K;

	for(int i = 0; i < K; ++i)
	{
		int cur, prev;
		cin >> cur >> prev;
		floyd[cur][prev] = true;
	}

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (floyd[i][j] == false && floyd[i][k] && floyd[k][j])
					floyd[i][j] = true;

	cin >> S;

	for(int i = 0; i < S; ++i)
	{
		int first, second;
		cin >> first >> second;

		if (floyd[first][second]) cout << -1 << "\n";
		else if (floyd[second][first]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	// BFS - 시간초과
	// 안 되는 이유 -> BFS의 시간복잡도는 O(V+E) E가 Dense할경우 N^2이고 문제에서는 50000으로 제한했지만 그래도 50000*S = 25억으로 시간초과
	//for (int i = 1; i <= K; ++i)
	//{
	//	int cur, prev;
	//	cin >> cur >> prev;
	//	cases[cur].push_back(prev);
	//}
	//for(int i = 0; i < S; ++i )
	//{
	//	int first;
	//	int second;

	//	cin >> first >> second;

	//	// first -> to lower
	//	queue<int> Q1;
	//	visited[first] = true;
	//	Q1.push(first);

	//	memset(visited, 0, sizeof(bool) * 401);

	//	bool b1 = false;
	//	while (!Q1.empty())
	//	{
	//		auto front = Q1.front();
	//		Q1.pop();

	//		if(front == second)
	//		{
	//			b1 = true;
	//			break;
	//		}

	//		for(int j = 0; j < cases[front].size(); ++j)
	//		{
	//			if (visited[cases[front][j]]) continue;
	//			visited[cases[front][j]] = true;
	//			Q1.push(cases[front][j]);
	//		}
	//	}

	//	memset(visited, 0, sizeof(bool) * 401);

	//	queue<int> Q2;
	//	visited[second] = true;
	//	Q2.push(second);

	//	bool b2 = false;
	//	while (!Q2.empty())
	//	{
	//		auto front = Q2.front();
	//		Q2.pop();

	//		if (front == first)
	//		{
	//			b2 = true;
	//			break;
	//		}

	//		for (int j = 0; j < cases[front].size(); ++j)
	//		{
	//			if (visited[cases[front][j]]) continue;
	//			visited[cases[front][j]] = true;
	//			Q2.push(cases[front][j]);
	//		}
	//	}

	//	if (b1) cout << -1 << "\n";
	//	else if (b2) cout << 1 << "\n";
	//	else cout << 0 << "\n";
	//}

	return 0;
}

// U : 3min
// T : 6min
// C : 1h15min