#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

struct tEdge
{
	int d;
	int w;
};

// backtracking 필요 
void dfs(int s, vector<long long>& AccTime, vector<vector<tEdge>>& adjList, vector<bool>& visited)
{
	if (adjList[s].empty())
	{
		visited[s] = true;
		return;
	}

	if (visited[s]) return;

	// s의 인접리스트 중 vecAccTime이 0이고 자식이 없을 때 까지 내려가며 갱신
	long long Max = 0;
	for(auto edge : adjList[s])
	{
		dfs(edge.d, AccTime, adjList, visited);
		Max = std::max(Max, AccTime[edge.d] + edge.w);
	}

	AccTime[s] = Max;
	visited[s] = true;
}

int main()
{
	fastio;

	int T, N, K, X, Y, W;

	cin >> T;

	
	for(int i = 0; i < T; ++i)
	{
		cin >> N >> K;
		// 건물번호 1부터 시작
		vector<int> vecTime(N+1);
		for(int j = 1; j <= N; ++j )
		{
			cin >> vecTime[j];
		}

		vector<vector<tEdge>> adjList(N + 1);
		for(int j = 0; j < K; ++j)
		{
			cin >> X >> Y;
			adjList[Y].push_back({X, vecTime[X]});
		}

		cin >> W;
		vector<long long> vecAccTime(N + 1);
		vector<bool> visited(N + 1);
		dfs(W, vecAccTime, adjList, visited);

		cout << vecAccTime[W] + vecTime[W] << "\n";
	}

	return 0;
}

// 각 건물들은 선행되는 테크가 있음
// 특정건물을 지을 때 까지 걸리는 최소 시간을 구하라

// T 테스트케이스
// N 건물의 갯수 2 - 1000
// K 건설 규칙의 갯수 1 - 100,000
// 건물 X 지으면 -> Y를 지을 수 있음
// W 지을 건물

// 인접리스트로 표현 -> 인접이 지어져야 자신 지어질 수 있음
// W가 지어지기 위해서는 자신의 인접들 중 가장 누적 시간이 큰 애가 지어져야 함
// 자식들의 누적시간을 모르기 때문에 재귀적으로 가장 밑바닥으로 갈 때까지 찾음
// 밑에서부터 누적함 Bottom-Top

// S : 2:58
// U : 2:59 1min
// T : 3:04 5min
// C : 3:55 51min -> 문제조건 제대로 확인 안 함 건물을 짓는 시간이 0인 경우.