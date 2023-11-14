#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>

// N : 논의 갯수 1 - 300
// 물을 대는 방법 2가지
// 1. 직접 논에 우물 파기
// 2. 이미 물을 대고 있는 다른 논으로부터 물 끌어오기
// 각각 논에 대해 우물 파는 비용과 논들 사이에 물을 끌어오는 비용이 주어짐
// 최소 비용으로 모든 논에 물을 대라.

// 최소 신장 트리를 구하고 그 중 가장 작은 우물을 파는데 드는 비용을 가진 논에 우물을 판다.

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

	// i에서 j로 물을 주었을 때
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

	// 연결 그래프 안에 있는 요소들 중 가장 작은 요소를 ans에 더해줌
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