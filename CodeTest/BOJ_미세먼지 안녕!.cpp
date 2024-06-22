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
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int INF = 0x3f3f3f3f;

int r, c, t;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int board[52][52]{};
int addboard[52][52]{};
bool OOB(int y, int x)
{
	return y <= 0 || x <= 0 || y > r || x > c;
}

int main()
{
	fastio;
	cin >> r >> c >> t;

	int aircondn;
	int total = 0;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
		{
			cin >> board[i][j];
			
			if (board[i][j] == -1)
				aircondn = i;
			else
				total += board[i][j];
		}

	int airconup = aircondn - 1;
	

	while (t--)
	{
		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j)
			{
				if (board[i][j] <= 4) continue;
				int spreadPower = board[i][j] / 5;
				for(int k = 0; k < 4; ++k)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (OOB(ny, nx) || board[ny][nx] == -1) continue;
					board[i][j] -= spreadPower;
					addboard[ny][nx] += spreadPower;
				}
			}

		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j)
			{
				if (addboard[i][j] <= 0) continue;
				board[i][j] += addboard[i][j];
				addboard[i][j] = 0;
			}

		// circulate
		total -= board[airconup - 1][1];
		for(int i = airconup - 2; i >= 1; --i)
			board[i + 1][1] = board[i][1];
		for (int i = 2; i <= c; ++i)
			board[1][i - 1] = board[1][i];
		for (int i = 2; i <= airconup; ++i)
			board[i-1][c] = board[i][c];
		for (int i = c - 1; i >= 2; --i)
			board[airconup][i + 1] = board[airconup][i];
		board[airconup][2] = 0;

		total -= board[aircondn + 1][1];
		for (int i = aircondn + 2; i <= r; ++i)
			board[i - 1][1] = board[i][1];
		for (int i = 2; i <= c; ++i)
			board[r][i - 1] = board[r][i];
		for (int i = r-1; i >= aircondn; --i)
			board[i+1][c] = board[i][c];
		for (int i = c - 1; i >= 2; --i)
			board[aircondn][i + 1] = board[aircondn][i];
		board[aircondn][2] = 0;
	}

	cout << total;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :