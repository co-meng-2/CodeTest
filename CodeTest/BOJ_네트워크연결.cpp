#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// N개의 정점과 M개의 간선을 가지는 그래프로부터 최소 신장트리를 크루스칼 알고리즘을 통해 

int Find(int n, vector<int>& p)
{
	if (p[n] < 0) return n;
	p[n] = Find(p[n], p);
	return p[n];
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


struct tEdge
{
	int s;
	int d;
	int w;
	
	const bool operator <(const tEdge& _rhs)
	{
		return w < _rhs.w;
	}
};

int main()
{
	fastio;

	int N, M;
	cin >> N >> M;

	vector<tEdge> edges;

	for (int i = 0; i < M; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		edges.push_back({ s, d, w });
	}

	std::sort(edges.begin(), edges.end());

	vector<int> p(N+1, -1);
	int ans = 0;
	for (int i = 0; i < M; ++i)
	{
		if (Union(edges[i].s, edges[i].d, p))
		{
			ans += edges[i].w;
		}
	}

	cout << ans;

	return 0;
}


// S : 7:13
// U : 7:14
// T : 7:14
// C : 7:22
// Total : 9min