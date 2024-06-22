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


bool sdoku[9][9][9]{};

bool bEnd = false;

void Select(int cy, int cx, int num)
{
	// 자신 가로 세로
	for (int j = 0; j < 9; ++j)
	{
		if (j != num)
			sdoku[cy][cx][j] = false;
		if (j != cx)
			sdoku[cy][j][num] = false;
		if (j != cy)
			sdoku[j][cx][num] = false;
	}

	int muli = cy / 3;
	int mulj = cx / 3;

	// 칸
	for (int si = muli * 3; si < 3 * (muli + 1); si++)
		for (int sj = mulj * 3; sj < 3 * (mulj + 1); sj++)
		{
			if (si == cy && sj == cx) continue;
			sdoku[si][sj][num] = false;
		}
}

void dfs(int cy, int cx)
{
	if (bEnd) return;
	if (cy == 9)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				for (int k = 0; k < 9; ++k)
					if (sdoku[i][j][k])
						cout << k + 1;
			cout << "\n";
		}
		bEnd = true;
		return;
	}

	for (int num = 0; num < 9; ++num)
	{
		if (sdoku[cy][cx][num] == false) continue;

		bool tmp[9][9][9];
		copy(&sdoku[0][0][0], &sdoku[0][0][0] + 9 * 9 * 9, &tmp[0][0][0]);

		Select(cy, cx, num);

		int nx = cx + 1;
		int ny = cy;
		if (nx == 9)
		{
			nx = 0;
			ny++;
		}

		dfs(ny, nx);
		move(&tmp[0][0][0], &tmp[0][0][0] + 9 * 9 * 9, &sdoku[0][0][0]);
	}
}


int main()
{
	fastio;
	memset(sdoku, true, sizeof(sdoku));

	char n;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			cin >> n;
			int  num = n - '0' - 1;

			if (num < 0) continue;

			Select(i, j, num);
		}

	dfs(0, 0);

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :