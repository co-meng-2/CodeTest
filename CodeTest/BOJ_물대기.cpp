#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>

// N : ���� ���� 1 - 300
// ���� ��� ��� 2����
// 1. ���� �� �칰 �ı�
// 2. �̹� ���� ��� �ִ� �ٸ� �����κ��� �� �������
// ���� �� ���� �칰 �Ĵ� ���� ��� ���̿� ���� ������� ����� �־���
// �ּ� ������� ��� �� ���� ���.

// �ּ� ���� Ʈ���� ���ϰ� �� �� ���� ���� �칰�� �Ĵµ� ��� ����� ���� �� �칰�� �Ǵ�.

struct tInfo
{
	int s;
	int d;
	int val;

	bool operator <(const tInfo& _rhs) const
	{
		return val < _rhs.val;
	}
};

int Find(int n, vector<int>& p)
{
	if (p[n] < 0) return n;
	return p[n] = Find(p[n], p);
}

bool Union(int parent, int child, vector<int>& p, int val)
{
	parent = Find(parent, p);
	child = Find(child, p);

	if (parent == child) return false;

	if (-p[parent] < val && -p[child] < val) return false;

	p[parent] = -std::min(-p[parent], -p[child]);
	p[child] = parent;

	return true;
}

int main()
{
	int N;
	cin >> N;
	vector<int> v;

	// i���� j�� ���� �־��� ��
	vector<bool> visited(N);

	for(int i = 0; i < N; ++i)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}

	vector<tInfo> edges;

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			int val;
			cin >> val;
			if (val > 0  && v[i] > val)
				edges.push_back({ i, j,  val});
		}
	}

	std::sort(edges.begin(), edges.end());
	vector<int> p(N);
	for(int i = 0; i < N; ++i)
	{
		p[i] = -v[i];
	}

	int ans = 0;
	for(int i = 0; i < edges.size(); ++i)
	{
		if(Union(edges[i].s, edges[i].d, p, edges[i].val))
		{
			ans += edges[i].val;
		}
	}

	// ���� �׷��� �ȿ� �ִ� ��ҵ� �� ���� ���� ��Ҹ� ans�� ������
	for(int i = 0; i < N; ++i)
	{
		if(p[i] < 0 )
		{
			ans += -p[i];
		}
	}

	cout << ans;

	return 0;
}

// S : 3:41
// U : 3:43
// T : 3:50
// C :
// Total :