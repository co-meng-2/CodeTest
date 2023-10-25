#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <cmath>


// ������ ������ ���� ����
// r�� c������ A[r][c]���� �� �� ����.
// ��� ����� 1x1 ũ��
// �α� �̵� �Ϸ� ���� ������ ���� ����
// �α� �̵��� ���ٸ� ��

// ���
// ���漱 ���� �� ������ �α� ���̰� L���̻� R������ -> ���漱 ����.
// ���漱 ���� �ִ� �׷��� -> ����
// ������ �� ĭ�� �α����� ������ �α��� / ���� ĭ �� (�Ҽ����� ����)
// ���� ��ü�ϰ� ���漱�� �ݴ´�.

// ����
// ��ĥ���� �α� �̵��� �Ͼ�°�?

// ���� ũ�� N (1-50)
// L, R 1 - 100

// Ǯ��
// ���Ͽ� ���ε带 �̿�?
// �� ���� ���� �ο�
// �� ���󿡼� �����¿쿡 ���ؼ� LR üũ
// ���� ���̶�� �ΰ� union
// �� �׷����� �ִ� �������� �α��� ��ġ�� �ٽ� ����

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
	// ���Ϸθ� �˻�
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