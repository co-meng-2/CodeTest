#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// x,y,z를 정렬 후, n+1 - n값으로 간선의 가중치를 계산
// 총 x, y, z의 3가지 경우의 간선들이 나옴
// 그러면 이 3가지로 크루스칼을 진행

struct tInfo
{
	int loc;
	int index;

	bool operator<(const tInfo& _rhs) const
	{
		return loc < _rhs.loc;
	}
};

struct tEdge
{
	int s;
	int d;
	int w;

	bool operator<(const tEdge& _rhs) const
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
	fastio;

	int n;
	cin >> n;
	vector<vector<tInfo>> locations(3, vector<tInfo>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
		{
			cin >> locations[j][i].loc;
			locations[j][i].index = i;
		}

	for (int i = 0; i < 3; ++i)
		std::sort(locations[i].begin(), locations[i].end());

	vector<tEdge> edges;
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 1; i < n; ++i)
		{
			tEdge edge;
			edge.w = locations[j][i].loc - locations[j][i - 1].loc;
			edge.s = locations[j][i].index;
			edge.d = locations[j][i-1].index;
			edges.push_back(edge);
		}
	}
	std::sort(edges.begin(), edges.end());
	
	vector<int> p(n, -1);
	int minv = 0;
	for (auto edge : edges)
	{
		if (Union(edge.s, edge.d, p))
		{
			minv += edge.w;
		}
	}
	
	cout << minv;

	return 0;
}


// S : 4:30
// U : 4:31
// T : 4:35
// C : 5:07
// Total : 37 min