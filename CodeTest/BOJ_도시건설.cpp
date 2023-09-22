#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// ����
// ��� ����ġ �� - �ּҽ���Ʈ���� ����ġ ���� ���϶� 

// ����
// �ǹ��� ���� N 3 ~ 10e5
// ������ ���� M 2 ~ 5*10e5
// ��� c  1- 10e6

// Ǯ��
// ũ�罺Į : ��� ������ priority_queue�� �����鼭 ����
// ���� ���� ����
// ���� ���� ���� �� ���� union�غ�
// ���� -> ����ġ ��ģ��
// ���� -> �ƹ��͵� �� ��

int N, M;
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
tSDW arrEdge[5000001]{};

int p[100001]{};
int Find(int n)
{
	if (p[n] < 0) return n;
	return p[n] = Find(p[n]);
}

bool Union(int parent, int child)
{
	parent = Find(parent);
	child = Find(child);

	if (parent == child) return false;
	p[parent] += p[child];
	p[child] = parent;
	return true;
}

int main()
{
	cin >> N >> M;

	// 
	std::fill(p + 1, p + N + 1, -1);
	long long sumW = 0;
	for(int i = 1; i <= M; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		arrEdge[i] = { s,d,w };
		sumW += w;
	}

	std::sort(arrEdge + 1, arrEdge + 1 + M);

	long long sumMin = 0;
	for(int i = 1; i <= M; ++i)
	{
		if(Union(arrEdge[i].s, arrEdge[i].d))
			sumMin += arrEdge[i].w;
	}

	bool isConnected = true;
	int cnt = 0;
	for(int i = 1; i <= N; ++i)
	{
		if (p[i] < 0) cnt++;
		if(cnt == 2)
		{
			isConnected = false;
			break;
		}
	}
	// ��� �ǹ� ���� ����
	if (isConnected)
		cout << sumW - sumMin;
	else
		cout << -1;

	return 0;
}

// U : 2min
// T : 5min
// C : 16min