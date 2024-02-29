#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <set>

// 유니온 할 때, 발전소와 연결된 노드끼리는 잇지 않는다.

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

bool Union(int parent, int child, vector<int>& p, const std::set<int>& s)
{
	parent = Find(parent, p);
	child = Find(child, p);

	if (s.find(child) != s.end())
	{
		std::swap(parent, child);
	}

	if (parent == child || (s.find(parent) != s.end() && s.find(child) != s.end()))
	{
		return false;
	}

	p[parent] += p[child];
	p[child] = parent;
	return true;
}

int main()
{
	fastio;

	int N, M, K;
	cin >> N >> M >> K;
	std::set<int> generators;
	for (int i = 0; i < K; ++i)
	{
		int g;
		cin >> g;
		generators.insert(g);
	}

	vector<tEdge> vecNode;
	for (int i = 0; i < M; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		// BAD
		//if (generators.find(d) != generators.end())
		//{
		//	int tmp = s;
		//	s = d;
		//	d = tmp;
		//}
		vecNode.push_back({ s,d,w });
	}

	int sum = 0;
	std::sort(vecNode.begin(), vecNode.end());
	vector<int> p(N+1, -1);
	for (int i = 0; i < M; ++i)
	{
		if (Union(vecNode[i].s, vecNode[i].d, p, generators))
		{
			sum += vecNode[i].w;
		}
	}
	cout << sum;

	return 0;
}


// S : 9:31
// U : 9:33
// T : 9:36
// C : 10:34
// Total : 1h3min