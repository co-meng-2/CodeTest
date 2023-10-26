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
	// 1���� ����
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

// ��� ���
// ���� ���б� - ����  ���б��� ����
// � ���б����� ��� ���б��� �̵� ����
// �� ����� ���̴� �ִ� �Ÿ�
// ��� ����� �ִ� �Ÿ���?

// N �б��� �� 2-1000
// M ������ �� 1-10000
// d �Ÿ� 1-1000

// �ּ� ���� Ʈ�� -> ũ�罺Į

// ũ�罺Į
// 1. edge�� w�������� ���� �� ���� ����
// 2. edge�� �� ���� �������� Union�غ���.
// 3. ��� edge�� ���� Union������ �ּ� ���� Ʈ���� ���̸� ���� �� �ִ�.

// M-W�θ� ������ �̷������ �Ѵٴ� ����
// �̰� edge���͸� ���� �� �̸� �������� �����ϸ� �� ��.

// S : 10:08
// U : 10:09 1min
// T : 10:16 7min
// C : 10:29 13min
// Total : 21min