#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <cmath>


// 각각의 땅에는 나라가 존재
// r행 c열에는 A[r][c]명이 살 고 있음.
// 모든 나라는 1x1 크기
// 인구 이동 하루 동안 다음과 같이 진행
// 인구 이동이 없다면 끝

// 방법
// 국경선 공유 두 나라의 인구 차이가 L명이상 R명이하 -> 국경선 연다.
// 국경선 열려 있는 그래프 -> 연합
// 연합의 각 칸의 인구수는 연합의 인구수 / 연합 칸 수 (소수점은 버림)
// 연합 해체하고 국경선을 닫는다.

// 문제
// 며칠동안 인구 이동이 일어나는가?

// 보드 크기 N (1-50)
// L, R 1 - 100

// 풀이
// 유니온 파인드를 이용?
// 각 나라에 숫자 부여
// 각 나라에서 상하좌우에 대해서 LR 체크
// 범위 안이라면 두개 union
// 한 그래프에 있는 정점들의 인구수 합치고 다시 갱신

int N, L, R;
int board[51][51]{};

int p[2501]{};
int v[2501]{};

int Find(int n)
{
	if (p[n] < 0) return n;
	return p[n] = Find(p[n]);
}

void Union(int parent, int child)
{
	parent = Find(parent);
	child = Find(child);

	if (parent == child) return;
	p[parent] += p[child];
	p[child] = parent;
}

struct tPos
{
	int y;
	int x;
};

int main()
{
	cin >> N >> L >> R;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> board[i][j];

	tPos arrDir[2] = {{0,1}, {1,0}};

	int answer = 0;
	// 우하로만 검사
	while (true)
	{
		int unionCnt = 0;
		std::fill(p + 1, p + N * N + 1, -1);
		std::fill(v + 1, v + N * N + 1, 0);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				for (int k = 0; k < 2; ++k)
				{
					int y = i + arrDir[k].y;
					int x = j + arrDir[k].x;

					if (y < 1 || y > N || x < 1 || x > N) continue;

					if (abs(board[i][j] - board[y][x]) >= L && abs(board[i][j] - board[y][x]) <= R)
					{
						Union(j + (i - 1) * N, x + (y - 1) * N);
						unionCnt++;
					}
				}
			}
		}

		if (unionCnt == 0)
			break;

		for(int i = 1; i <= N; ++i)
		{
			for(int j= 1; j <= N; ++j)
			{
				int curIdx = j + (i - 1) * N;
				v[Find(curIdx)] += board[i][j];
			}
		}

		for(int i = 1; i <= N; ++i)
		{
			for(int j = 1; j <=N; ++j)
			{
				int curIdx = j + (i - 1) * N;
				board[i][j] = v[Find(curIdx)] / -p[Find(curIdx)];
			}
		}
		answer++;
	}

	cout << answer;

	return 0;
}

// U : 6min
// T : 2miin
// C : 28min
// T : 36min