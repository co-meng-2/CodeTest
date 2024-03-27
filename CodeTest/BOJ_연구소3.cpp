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
using namespace std;

using ll = long long;
using pii = pair<int, int>;

// 12500 * 10C5
// 가능


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };



int main()
{
	fastio;

	int n, m;
	cin >> n >> m;
	const int INF = 10000000;
	vector<vector<int>> board(n+2, vector<int>(n+2, INF));
	vector<pii> viruses;
	for(int i = 1 ; i<= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				board[i][j] = 0;
				viruses.push_back({ i, j });
			}
			else if (board[i][j] == 1)
			{
				board[i][j] = INF;
			}
			else if (board[i][j] == 0)
			{
				board[i][j] = -1;
			}
		}
	}

	vector<bool> forPermu;
	for (int i = 0; i < viruses.size() - m; ++i)
	{
		forPermu.push_back(false);
	}
	for(int i = 0; i < m; ++i)
	{
		forPermu.push_back(true);
	}

	int mn = INF;
	bool check = false;

	auto save = board;
	do
	{
		board = save;
		queue<pii> Q;

		vector<vector<bool>> visited(n + 2, vector<bool>(n + 2, false));

		for (int i = 0; i < viruses.size(); ++i)
		{
			if (forPermu[i])
			{
				Q.push({ viruses[i] });
				visited[viruses[i].first][viruses[i].second] = true;
			}
		}

		while (!Q.empty())
		{
			auto [cy, cx] = Q.front();
			Q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (board[ny][nx] <= 0 && visited[ny][nx] == false)
				{
					visited[ny][nx] = true;
					board[ny][nx] = board[cy][cx] + 1;
					Q.push({ ny, nx });
				}
			}
		}

		int mx = 0;
		int check2 = true;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				pii ij{ i,j };
				if ( /*find(viruses.begin(), viruses.end(), ij) == viruses.end() &&*/ board[i][j] != INF && board[i][j] > mx)
				{
					mx = board[i][j];
				}
				if (board[i][j] < 0)
					check2 = false;
			}
		}

		if(check2)
			mn = min(mx, mn);
		check |= check2;

	} while (next_permutation(forPermu.begin(), forPermu.end()));


	if (check == false)
		cout << -1;
	else
		cout << mn;

	return 0;
}


// S : 10:24
// U : 10:25
// T : 10:31
// C :
// Total :