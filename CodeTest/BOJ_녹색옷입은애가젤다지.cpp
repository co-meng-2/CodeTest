#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>


// queue로 지점에 대한 threshold를 두면 되지 않을까?

struct tInfo
{
	int y;
	int x;
	int w;

	bool operator>(const tInfo& _rhs)
	{
		return w > _rhs.w;
	}
};

int dx[4] = { 1,-1 , 0 ,0 };
int dy[4] = { 0 ,0,1,-1 };

int main()
{
	fastio;

	int testcase = 1;
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		int INF = 1000000000;
		vector<vector<int>> board(n + 2, vector<int>(n + 2, INF));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				cin >> board[i][j];

		vector<vector<bool>> visited(n + 2, vector<bool>(n + 2, false));
		vector<vector<int>> table(n + 2, vector<int>(n + 2, INF));

		std::priority_queue<tInfo,vector<tInfo>, std::greater<>> PQ;
		PQ.push({1,1,0});
		while (!PQ.empty())
		{
			auto [cy, cx, cw] = PQ.top();
			PQ.pop();

			if (visited[cy][cx]) continue;
			visited[cy][cx] = true;

			for (int i = 0; i < 4; ++i)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				int nw = cw + board[ny][nx];

				if (nw < table[ny][nx])
				{
					table[ny][nx] = nw;
					PQ.push({ny, nx, nw});
				}
			}
		}

		cout << "Problem " << testcase << ": " << table[n][n] + board[1][1] << "\n";





		//vector<vector<int>> values(n + 2, vector<int>(n + 2, INF ));
		//std::queue<tInfo> q;
		//q.push({ 1,1,board[1][1] });
		//while (!q.empty())
		//{
		//	auto [cy, cx, cw] = q.front();
		//	q.pop();

		//	for (int i = 0; i < 4; ++i)
		//	{
		//		int ny = cy + dy[i];
		//		int nx = cx + dx[i];
		//		int nw = cw + board[ny][nx];

		//		if (nw >= values[ny][nx]) continue;
		//		values[ny][nx] = nw;
		//		q.push({ ny, nx, nw });
		//	}
		//}

		//cout << "Problem " << testcase << ": " << values[n][n] <<"\n";
		testcase++;
	}
	

	return 0;
}


// S : 9:42
// U : 9:45
// T : 9:50
// C : 10:00
// Total : 18min