#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <climits>

int N; // 집 2 - 100'000
int M; // 길 1 - 1'000'000 

// 2개로 마을을 분리
// 분리된 마을 안의 집들이 서로 연결 되어야 함
// 마을에는 집이 하나 이상 존재
// 분리된 두 마을 사이에 있는 길들은 없앤다.
// 분리된 마을 안에서도 두 집 사이에 경로가 존재만 하면 됨.
// 유지비의 합이 최소

int p[100001]{};

struct tSDW
{
	int s;
	int d;
	int w;

	bool operator<(const tSDW& _rhs) const
	{
		return w < _rhs.w;
	}
};

int Find(int _n)
{
	if (p[_n] < 0) return _n;
	return p[_n] = Find(p[_n]);
}

bool Union(int _parent, int _child)
{
	_parent = Find(_parent);
	_child = Find(_child);

	if (_parent == _child) return false;
	
	p[_parent] += p[_child];
	p[_child] = _parent;
	return true;
}

int main()
{
	fastio;

	cin >> N >> M;
	// 임의의 두 집 사이에 경로가 항상 존재
	// 그래프 하나로 구성되어 있다.
	// 최소 신장트리를 만들고  그 중에서 가장 큰 가중치를 가진 간선을 빼준다.
	vector<tSDW> vec;
	vec.reserve(M);
	for (int i = 0; i < M; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		vec.push_back({ s, d, w });
	}

	std::sort(vec.begin(), vec.end(), std::greater<tSDW>());
	std::fill(p, p + N + 1, -1);

	long long ans = 0;
	int maxV = -INT_MAX;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (Union(vec[i].s, vec[i].d))
		{
			maxV = std::max(maxV, vec[i].w);
			ans += vec[i].w;
		}
	}
	
	cout << ans - maxV;

	return 0;
}