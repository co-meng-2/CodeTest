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
	int s;
	int d;
	int w;

	bool operator<(const tEdge& _rhs)
	{
		return w < _rhs.w;
	}
};

int Find(int n, vector<int>& p)
{
	if (p[n] < 0) return n;
	return p[n] = Find(p[n], p);
}

bool Union(int parent, int child, vector<int>& p)
{
	parent = Find(parent, p);
	child = Find(child, p);

	if (parent == child) return false;

	p[parent] += p[child];
	p[child] = parent;
	return true;
}

int main()
{
	int N, M;
	cin >> N >> M;
	// 1부터 시작
	vector<char> edgeType(N + 1);
	for(int i = 1; i <= N ; ++i)
	{
		cin >> edgeType[i];
	}

	vector<tEdge> edges;
	for(int i = 0; i < M; ++i)
	{
		int u, v, d;
		cin >> u >> v >> d;
		if (edgeType[u] != edgeType[v])
			edges.push_back({ u, v, d });
	}

	vector<int> p(N + 1, -1);
	std::sort(edges.begin(), edges.end());
	int sumW = 0;
	int cnt = 0;
	for(int i = 0; i < edges.size(); ++i)
	{
		if (Union(edges[i].s, edges[i].d, p))
		{
			sumW += edges[i].w;
			cnt++;
		}
	}

	if (cnt != N - 1)
		cout << -1;
	else
		cout << sumW;

	return 0;
}

// 사심 경로
// 남초 대학교 - 여초  대학교를 연결
// 어떤 대학교에서 모든 대학교로 이동 가능
// 이 경로의 길이는 최단 거리
// 사심 경로의 최단 거리는?

// N 학교의 수 2-1000
// M 도로의 수 1-10000
// d 거리 1-1000

// 최소 신장 트리 -> 크루스칼

// 크루스칼
// 1. edge를 w기준으로 작은 것 부터 정렬
// 2. edge의 두 점을 기준으로 Union해본다.
// 3. 모든 edge에 대해 Union했으면 최소 신장 트리의 길이를 구할 수 있다.

// M-W로만 간선이 이루어져야 한다는 조건
// 이건 edge벡터를 만들 때 미리 조건으로 선별하면 될 듯.

// S : 10:08
// U : 10:09 1min
// T : 10:16 7min
// C : 10:29 13min
// Total : 21min