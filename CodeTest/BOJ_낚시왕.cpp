#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0,0,1,-1 };

// 100 * 10000 * (1000 -> / % 로 위치 바로 특정 ?)

struct tShark
{
	int r;
	int c;
	int spd;
	pii dir;
	int size;
	bool valid = true;
};

int board[100][100]{};
tShark sharks[10000]{};
int main()
{
	fastio;

	int row, col, m;
	cin >> row >> col >> m;

	memset(board, -1, sizeof(board));
	for(int i = 0; i < m; ++i)
	{
		int dir;
		cin >> sharks[i].r >> sharks[i].c >> sharks[i].spd >> dir >> sharks[i].size;
		// 인덱스 맞추기
		sharks[i].r--;
		sharks[i].c--;
		dir--;
		sharks[i].dir.first = dy[dir];
		sharks[i].dir.second = dx[dir];
		board[sharks[i].r][sharks[i].c] = i;
	}
	int sum = 0;

	// 다음 위치, 방향 결정
	auto NextPos = [](int& elem, int& dir, int mx)
	{
		int dircnt = elem / (mx - 1); // 튕긴 횟수
		int rmn = elem % (mx - 1); // 나머지
		if (dircnt % 2)
			dir *= -1;
		if (dir < 0)
			elem = mx - 1 - rmn;
		else if (dir > 0)
			elem = rmn;
	};

	for(int i = 0; i < col; ++i)
	{
		// 낚시
		for(int j = 0; j < row; ++j)
		{
			int sharkIdx = board[j][i];
			if( sharkIdx >= 0 )
			{
				sum += sharks[sharkIdx].size;
				sharks[sharkIdx].valid = false;
				break;
			}
		}

		// 보드 초기화 -> 새 보드에서 상어 쌓아가며 먹기 가능
		memset(board, -1, sizeof(board));

		int idx = -1;
		for (auto& [sr, sc, spd, dir, size, valid] : sharks)
		{
			idx++;
			if (!valid) continue;

			sr += dir.first * spd;
			sc += dir.second * spd;

			// NextPos함수를 써먹기 위해 양수화 시킴 -> 벽에 한 번 튕겼다고 생각,
			if (sr < 0) { sr *= -1; dir.first *= -1; }
			else if (sc < 0) { sc *= -1; dir.second *= -1; }

			if (sr >= row)
			{
				NextPos(sr, dir.first, row);
			}
			else if (sc >= col)
			{
				NextPos(sc, dir.second, col);
			}

			// 먹기
			if(board[sr][sc] >= 0)
			{
				if (sharks[board[sr][sc]].size > size)
				{
					valid = false;
				}
				else
				{
					sharks[board[sr][sc]].valid = false;
					board[sr][sc] = idx;
				}
			}
			else
			{
				board[sr][sc] = idx;
			}
		}
	}

	cout << sum;

	return 0;
}


// S : 614
// U : 
// T : 
// C :
// Total :