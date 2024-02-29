#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// ������ ����ġ 1 ������ 0���� ũ�罺Į�� ��� �� ��ü ����ġ�� ������ ���� �Ƿε�
// ũ�罺Į�� ���� �ּ� ����, �ִ� ���� Ʈ���� ����Ѵ�.

struct tEdge
{
	int s;
	int d;
	int w;

	bool operator<(const tEdge& _rhs) const
	{
		return w < _rhs.w;
	}
	bool operator>(const tEdge& _rhs) const
	{
		return w > _rhs.w;
	}
};

int Find(int n, vector<int>& p)
{
	if (p[n] < 0)  return n;
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

	int v, e;
	cin >> v >> e;

	vector<tEdge> edges;
	for (int i = 0; i < e+1; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		w = (w + 1) % 2;
		edges.push_back({ s, d, w });
	}

	vector<int> p(v+1, -1);
	std::sort(edges.begin(), edges.end());
	int minST = 0;
	for (auto edge : edges)
	{
		if (Union(edge.s, edge.d, p))
		{
			minST += edge.w;
		}
	}

	int maxST = 0;
	std::fill(p.begin(), p.end(), -1);
	std::sort(edges.begin(), edges.end(), std::greater<>());
	for (auto edge : edges)
	{
		if (Union(edge.s, edge.d, p))
		{
			maxST += edge.w;
		}
	}
	
	cout << maxST * maxST - minST * minST;

	return 0;
}


// S : 10:40
// U : 10:41
// T : 10:42
// C : 10:54
// Total :