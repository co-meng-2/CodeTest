#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <queue>
#include <algorithm>

// S : 6:06
// U : 6:09
// T : 6:15
// C : 7:30
// Total : 1h24min // 알바 가산점 40min

// permutation 이용한 brute force
// 인덱스에서 너무 해맸다.
// 보드를 뒤집어 생각해서 궁수를 0에 두고 생각했으면 더 편했을지도?
// 에너미를 움직이지말고 아처를 한칸씩 위로하는게 좋다!!!

int dx[3] = { -1, 0, 1 }; // L U R
int dy[3] = { 0, -1, 0 };

using pii = std::pair<int, int>;

bool OOB(int y, int x, int mx, int my)
{
	if (x < 0 || x >= mx || y < 0 || y >= my) return true;
	return false;
}

int AttackEnemy(vector<int>& permu, vector<vector<int>>& board, int& ecnt, int& d)
{
	vector<pii> attackPos;
	for(int archerX = 0; archerX < board[0].size(); ++archerX)
	{
		if (permu[archerX] == 0) continue;
		pii cur{board.size()-1, archerX};
		std::queue<pii> Q;
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		Q.push(cur);
		while(!Q.empty())
		{
			auto [cy, cx] = Q.front();
			Q.pop();

			if (visited[cy][cx]) continue;
			visited[cy][cx] = true;

			if (abs(cur.first - cy) + abs(cur.second - cx) > d)
				break;

			if(board[cy][cx] == 1)
			{
				attackPos.push_back({ cy, cx });
				break;
			}


			for(int i = 0; i < 3; ++i)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (OOB(ny, nx, board[0].size(), board.size())) continue;
				Q.push({ ny,nx });
			}
		}
	}

	int removed = 0;
	for(auto [y, x] : attackPos)
	{
		if (board[y][x])
		{
			board[y][x] = 0;
			removed++;
			ecnt--;
		}
	}

	return removed;
}

void MoveEnemy(vector<vector<int>>& board, int& ecnt)
{
	for(int i = board.size() - 2; i >= 0; --i)
	{
		for(int j =0; j < board[0].size(); ++j)
		{
			if (i == board.size() - 2 && board[i][j] == 1)
				ecnt--;
			board[i + 1][j] = board[i][j];

			if (i == 0)
				board[i][j] = 0;
			if (i == board.size() - 2)
				board[i + 1][j] = 0;
		}
	}
}

int GetMax(vector<int>& permu, vector<vector<int>> board, int ecnt, int& d)
{
	int totalRemoved = 0;
	while(ecnt != 0)
	{
		totalRemoved += AttackEnemy(permu, board, ecnt, d);
		MoveEnemy(board, ecnt);
	}
	return totalRemoved;
}



int main()
{
	fastio;

	int y, x, d;
	cin >> y >> x >> d;

	vector<vector<int>> board(y+1, vector<int>(x,-1));
	int etotal = 0;
	for(int i = 0; i < y; ++i)
	{
		for(int j = 0; j < x; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				etotal++;
		}
	}

	vector<int> permu;
	for (int i = 0; i < board[0].size() - 3; ++i)
		permu.push_back(0);
	for (int i = 0; i < 3; ++i)
		permu.push_back(1);

	int max = 0;
	do
	{
		max = std::max(max, GetMax(permu, board, etotal, d));
	} while (std::next_permutation(permu.begin(), permu.end()));

	cout << max;
	return 0;
}


