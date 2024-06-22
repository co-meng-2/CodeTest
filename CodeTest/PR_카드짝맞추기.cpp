#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <random>

using namespace std;
using pii = pair<int, int>;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

bool OOB(int y, int x)
{
	return !(y >= 0 && y < 4 && x >= 0 && x < 4);
}

bool OnBound(int y, int x)
{
	return (y == 0 || y == 3) || (x == 0 || x == 3);
}

int Move(pii cur, pii target, vector<vector<int>>& board)
{
	queue<pii> Q;
	Q.push(cur);

	vector<vector<int>> visited(4, vector<int>(4, 1e9));
	visited[cur.first][cur.second] = 0;
	while (!Q.empty())
	{
		auto [cy, cx] = Q.front();
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (OOB(ny, nx)) continue;

			if (!(visited[ny][nx] <= visited[cy][cx] + 1))
			{
				if (ny == target.first && nx == target.second)
				{
					return visited[cy][cx] + 1;
				}

				visited[ny][nx] = visited[cy][cx] + 1;
				Q.push({ ny, nx });
			}

			while (!OOB(ny, nx) && board[ny][nx] == 0)
			{
				ny += dy[i];
				nx += dx[i];
			}
			if (ny >= 4)
				ny--;
			if (ny < 0)
				ny++;
			if (nx >= 4)
				nx--;
			if (nx < 0)
				nx++;

			if (visited[ny][nx] <= visited[cy][cx] + 1) continue;
			if (ny == target.first && nx == target.second)
			{
				return visited[cy][cx] + 1;
			}
			visited[ny][nx] = visited[cy][cx] + 1;
			Q.push({ ny, nx });
		}
	}

	return 0;
}

int mn = 1e9;
vector<pii> cards;
vector<bool> cardVisited;
void dfs(pii cur, vector<vector<int>>& board, int total, int matchCnt)
{
	if (matchCnt == cards.size() / 2)
	{
		mn = min(mn, total);
		return;
	}

	int cy = cur.first;
	int cx = cur.second;

	if (board[cy][cx] > 0)
	{
		for (int row = 0; row < 4; ++row)
			for (int col = 0; col < 4; ++col)
				if (!(row == cy && col == cx) && board[row][col] == board[cy][cx])
				{
					int idx = -1;
					for (int x = 0; x < cards.size(); ++x)
						if (cards[x].first == row && cards[x].second == col)
						{
							idx = x;
							break;
						}

					int ret = Move(cur, { row, col }, board);
					int tmp = board[cy][cx];
					board[cy][cx] = 0;
					board[row][col] = 0;
					cardVisited[idx] = true;
					dfs({ row,col }, board, total + ret + 1, matchCnt + 1);
					board[cy][cx] = tmp;
					board[row][col] = tmp;
					cardVisited[idx] = false;
					row = 4;
					break;
				}
	}
	else
	{
		for (int i = 0; i < cards.size(); ++i)
		{
			if (cardVisited[i]) continue;

			int ret = Move(cur, cards[i], board);
			cardVisited[i] = true;
			dfs(cards[i], board, total + ret + 1, matchCnt);
			cardVisited[i] = false;
		}
	}
}

int solution(vector<vector<int>> board, int r, int c) {
	int answer = 0;

	int cnt = 0;
	int visitIdx = -1;
	for (int row = 0; row < board.size(); ++row)
		for (int col = 0; col < board.size(); ++col)
			if (board[row][col] > 0)
				cards.push_back({ row, col });

	cardVisited.resize(cards.size());

	for (int i = 0; i < cards.size(); ++i)
	{
		int ret = Move({ r,c }, cards[i], board);
		cardVisited[i] = true;
		dfs(cards[i], board, ret + 1, 0);
		cardVisited[i] = false;
	}


	answer = mn;
	return answer;
}

#define X first
#define Y second

int dist(vector<vector<int>>& board, pii src, pii dst) {
	int d[4][4];
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) d[i][j] = -1;
	d[src.X][src.Y] = 0;
	queue<pii> q;
	q.push(src);
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int en = 0; // dir 방향으로 진행할 때 카드 혹은 마지막 까지의 거리
			while (true) {
				int nx = cur.X + dx[dir] * en;
				int ny = cur.Y + dy[dir] * en;
				if (OOB(nx + dx[dir], ny + dy[dir]) || (en != 0 && board[nx][ny] != 0)) break;
				en++;
			}
			for (int z : {1, en}) {
				int nx = cur.X + dx[dir] * z;
				int ny = cur.Y + dy[dir] * z;
				if (OOB(nx, ny)) continue;
				if (d[nx][ny] == -1)
				{
					d[nx][ny] = d[cur.X][cur.Y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	return d[dst.X][dst.Y];
}

int solution1(vector<vector<int>>& board, int r, int c) {
	vector<pii> occur[7];

	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		if (board[i][j] == 0) continue;
		occur[board[i][j]].push_back({ i,j });
	}

	vector<int> p;
	for (int i = 1; i <= 6; i++) {
		if (!occur[i].empty()) p.push_back(i);
	}
	int n = p.size(); // 카드 종류의 개수
	int ans = 99999999;
	do { // 제거할 종류의 순서에 대한 permutation
		vector<vector<int>> myboard = board;
		int d[6][2];
		d[0][0] = dist(myboard, { r, c }, occur[p[0]][0]) + dist(myboard, occur[p[0]][0], occur[p[0]][1]);
		d[0][1] = dist(myboard, { r, c }, occur[p[0]][1]) + dist(myboard, occur[p[0]][1], occur[p[0]][0]);
		myboard[occur[p[0]][0].X][occur[p[0]][0].Y] = 0;
		myboard[occur[p[0]][1].X][occur[p[0]][1].Y] = 0;
		for (int i = 1; i < n; i++) {
			d[i][0] = min(d[i - 1][0] + dist(myboard, occur[p[i - 1]][1], occur[p[i]][0]), d[i - 1][1] + dist(myboard, occur[p[i - 1]][0], occur[p[i]][0])) + dist(myboard, occur[p[i]][0], occur[p[i]][1]);
			d[i][1] = min(d[i - 1][0] + dist(myboard, occur[p[i - 1]][1], occur[p[i]][1]), d[i - 1][1] + dist(myboard, occur[p[i - 1]][0], occur[p[i]][1])) + dist(myboard, occur[p[i]][1], occur[p[i]][0]);
			myboard[occur[p[i]][0].X][occur[p[i]][0].Y] = 0;
			myboard[occur[p[i]][1].X][occur[p[i]][1].Y] = 0;
		}
		ans = min({ ans, d[n - 1][0], d[n - 1][1] });
	} while (next_permutation(p.begin(), p.end()));
	return ans + 2 * n;
}



bool b = true;
void sibal(int depth, vector<vector<int>>& k)
{
	if (depth == 10)
	{
		if (solution(k, 3, 0) != solution1(k, 3, 0))
		{
			b = false;
			cout << 1111;
		}
		return;
	}

	bool check = false;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (k[i][j] != 0) continue;
			k[i][j] = depth / 2;
			sibal(depth + 1, k);
			k[i][j] = 0;
		}
	}
}

int main()
{

	vector<vector<int>> k2 = { {1,2,1,2},{3,3,4,4}, {5,5,6,0}, {6,0,0,0} };
	// 시드값을 얻기 위한 random_device 생성.
	std::random_device rd;

	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());

	// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis(0, 15);
	/*while(true)
	{
		swap(k2[dis(gen) / 4][dis(gen) / 4 % 4], k2[dis(gen) / 4][dis(gen) / 4 % 4]);

		int a = solution1(k2, 2, 2);
		int b = solution(k2, 2, 2);

		if (a != b)
			return 0;
	}*/
	int a = solution(k2, 2, 2);
	// int b = solution1(k2, 2, 2);
	

	return 0;
}