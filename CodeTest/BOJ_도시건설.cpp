#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 문제
// 모든 가중치 합 - 최소신장트리의 가중치 합을 구하라 

// 조건
// 건물의 개수 N 3 ~ 10e5
// 도로의 개수 M 2 ~ 5*10e5
// 비용 c  1- 10e6

// 풀이
// 크루스칼 : 모든 간선을 priority_queue에 넣으면서 판정
// 먼저 간선 정렬
// 간선 가장 작은 값 부터 union해봄
// 성공 -> 가중치 합친다
// 실패 -> 아무것도 안 함

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
	// 모든 건물 연결 판정
	if (isConnected)
		cout << sumW - sumMin;
	else
		cout << -1;

	return 0;
}

// U : 2min
// T : 5min
// C : 16min