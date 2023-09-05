#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <climits>

int N; // �� 2 - 100'000
int M; // �� 1 - 1'000'000 

// 2���� ������ �и�
// �и��� ���� ���� ������ ���� ���� �Ǿ�� ��
// �������� ���� �ϳ� �̻� ����
// �и��� �� ���� ���̿� �ִ� ����� ���ش�.
// �и��� ���� �ȿ����� �� �� ���̿� ��ΰ� ���縸 �ϸ� ��.
// �������� ���� �ּ�

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
	// ������ �� �� ���̿� ��ΰ� �׻� ����
	// �׷��� �ϳ��� �����Ǿ� �ִ�.
	// �ּ� ����Ʈ���� �����  �� �߿��� ���� ū ����ġ�� ���� ������ ���ش�.
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