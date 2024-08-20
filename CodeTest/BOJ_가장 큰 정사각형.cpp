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
#include <unordered_set>
#include <set>
#include <string>
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int board[1000][1000]{};
int boardtmp[1000][1000]{};

int check(int y, int x)
{
	int step = 1;
	int mxLength = board[y][x];

	int cy = y;
	int cx = x;
	while(true)
	{
		mxLength--;
		if (mxLength == 0)
			break;

		cy++;
		cx++;

		int curLength = board[cy][cx];

		if (curLength == 0)
			break;

		if(mxLength > curLength)
			mxLength -= (mxLength - curLength);

		step++;
	}

	return step;
}

int main()
{
	fastio;

	int r, c;
	cin >> r >> c;
	for(int i = 0 ; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
			boardtmp[i][j] = c - '0';
		}

	
	for (int i = 0; i < r; ++i)
	{
		for (int j = c - 1; j >= 0; --j)
		{
			if (boardtmp[i][j] == 0) continue;

			if(j+1 < c)
				boardtmp[i][j] += boardtmp[i][j+1];
		}
	}

	swap(board, boardtmp);

	for (int i = 0; i < c; ++i)
	{
		for (int j = r - 1; j >= 0; --j)
		{
			if (boardtmp[j][i] == 0) continue;

			if(j+1 < r)
				boardtmp[j][i] += boardtmp[j + 1][i];
		}
	}

	vector<pii> canMake[1001]{};
	for(int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			board[i][j] = min(board[i][j], boardtmp[i][j]);

			if (board[i][j])
				canMake[board[i][j]].push_back({ i,j });
		}

	int mx = 0;
	for(int num = min(r,c); num >= mx; --num)
	{
		for(auto [y, x] : canMake[num])
		{
			mx = max(check(y, x), mx);
		}
	}

	cout << mx * mx;

	return 0;
}

// S : 
// U : 
// T : 
// C :
// Total :
