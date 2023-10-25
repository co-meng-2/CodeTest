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

// backtracking �ʿ� 
void dfs(int s, vector<long long>& AccTime, vector<vector<tEdge>>& adjList, vector<bool>& visited)
{
	if (adjList[s].empty())
	{
		visited[s] = true;
		return;
	}

	if (visited[s]) return;

	// s�� ��������Ʈ �� vecAccTime�� 0�̰� �ڽ��� ���� �� ���� �������� ����
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
		// �ǹ���ȣ 1���� ����
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

// �� �ǹ����� ����Ǵ� ��ũ�� ����
// Ư���ǹ��� ���� �� ���� �ɸ��� �ּ� �ð��� ���϶�

// T �׽�Ʈ���̽�
// N �ǹ��� ���� 2 - 1000
// K �Ǽ� ��Ģ�� ���� 1 - 100,000
// �ǹ� X ������ -> Y�� ���� �� ����
// W ���� �ǹ�

// ��������Ʈ�� ǥ�� -> ������ �������� �ڽ� ������ �� ����
// W�� �������� ���ؼ��� �ڽ��� ������ �� ���� ���� �ð��� ū �ְ� �������� ��
// �ڽĵ��� �����ð��� �𸣱� ������ ��������� ���� �عٴ����� �� ������ ã��
// �ؿ������� ������ Bottom-Top

// S : 2:58
// U : 2:59 1min
// T : 3:04 5min
// C : 3:55 51min -> �������� ����� Ȯ�� �� �� �ǹ��� ���� �ð��� 0�� ���.