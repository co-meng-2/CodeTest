#include <iostream>
#include <queue>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 1번 없이 최소 신장트리 만드는데 드는 비용 + 순서쌍

// 1번 - K번 끊었을 때, K를 어디든지 연결 하기만 하면됨
// Matrix에서 Mat[k]중 가장 작은 값



struct tEdge
{
	int s;
	int d;
	int w;

	bool operator<(const tEdge& rhs) const
	{
		return w < rhs.w;
	}
};

using pii = std::pair<int, int>;

struct tInfo
{
	vector<pii> pairs;
	int totalW;
};

int Find(int n, vector<int>& p)
{
	if (p[n] < 0) return n;
	return p[n] = Find(p[n], p);
}

bool Union(int child, int parent, vector<int>& p)
{
	child = Find(child, p);
	parent = Find(parent, p);
	if (child == parent) return false;

	p[parent] += p[child];
	p[child] = parent;
	return true;
}


int main()
{
	fastio;

	int v, e;

	cin >> v >> e;

	vector<tEdge> edges;
	vector<bool> connected(v + 1, false);
	vector<vector<int>> adjMat(v + 1, vector<int>(v + 1, -1));
	for(int i = 0; i < e; ++i)
	{
		int s, d;
		cin >> s >> d;
		connected[s] = true;
		connected[d] = true;
		edges.push_back({ s, d});
	}

	vector<tEdge> edges2;
	const int INF = 1'000'000'000;
	vector<tInfo> rowLeastWs(v + 1);
	for(int i = 1; i <= v; ++i)
	{
		rowLeastWs[i].totalW = INF;
		for (int j = 1; j <= v; ++j)
		{
			cin >> adjMat[i][j];
			if (i < j && i != 1 && j != 1)
				edges2.push_back({ i, j, adjMat[i][j]});
			if(i != j && rowLeastWs[i].totalW > adjMat[i][j])
			{
				if(rowLeastWs[i].pairs.empty())
					rowLeastWs[i].pairs.push_back({ i,j });
				else
					rowLeastWs[i].pairs.front() = {i,j};
				rowLeastWs[i].totalW = adjMat[i][j];
			}
		}
	}

	vector<int> p(v + 1, -1);
	for(auto edge : edges)
	{
		Union(edge.s, edge.d, p);
	}

	std::sort(edges2.begin(), edges2.end());
	tInfo ans{};
	for(auto edge : edges2)
	{
		if (Union(edge.s, edge.d, p))
		{
			ans.totalW += adjMat[edge.s][edge.d];
			ans.pairs.push_back({ edge.s, edge.d });
		}
	}

	tInfo rowLeastMax{};
	for(int i = 2; i <= v; ++i)
	{
		if(connected[i]) continue;
		if (rowLeastWs[i].totalW > rowLeastMax.totalW)
		{
			rowLeastMax = rowLeastWs[i];
		}
	}

	ans = ans.totalW > rowLeastMax.totalW ? ans : rowLeastMax;

	cout << ans.totalW << " " << ans.pairs.size() << "\n";
	for(auto [i,j] : ans.pairs)
	{
		cout << i << " " << j << "\n";
	}

	return 0;
}


// S :
// U : 
// T : 
// C :
// Total :