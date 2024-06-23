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

int dx[6] = { -1,1,0,0, 0, 0 };
int dy[6] = { 0,0,-1,1, 0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// O
// 돌리기 : 25
// 순서 정하기 : 5! = 120
// 돌린 경우의 수 : 4 ^ 5 = 1024
// bfs : 125 + 125 * 6 = 875
// 대강 1억 넘음 -> 

int board[5][5][5]{};
int newboard[5][5][5]{};


// 0,1 -> 1, 4 -> 4,3 -> 3, 0
void Rotate(int z)
{
	int tmpboard[5][5]{};
	copy(&newboard[z][0][0], &newboard[z][0][0] + 5 * 5, &tmpboard[0][0]);
	for (int r = 0; r < 5; ++r)
		for (int c = 0; c < 5; ++c)
			newboard[z][r][c] = tmpboard[c][4 - r];
}

bool OOB(int z, int y, int x)
{
	return z < 0 || y < 0 || x < 0 || z >= 5 || y >= 5 || x >= 5;
}

int ans = INF;
void dfs(int curZ, vector<int>& rotate, vector<int>& orders)
{
	if (curZ == 5)
	{

	}

	for (int rotateCnt = 0; rotateCnt < 4; ++rotateCnt)
	{
		rotate.push_back(rotateCnt);
		dfs(curZ + 1, rotate, orders);
		rotate.pop_back();
	}

}

int main()
{
	fastio;

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			for (int k = 0; k < 5; ++k)
				cin >> board[i][j][k];

	vector<int> permu = { 0,1,2,3,4 };

	do
	{
		for (int i = 0; i < permu.size(); ++i)
			copy(&board[permu[i]][0][0], &board[permu[i]][0][0] + 5 * 5, &newboard[i][0][0]);

		for (int a = 0; a < 4; ++a)
		{
			Rotate(0);
			for (int b = 0; b < 4; ++b)
			{
				Rotate(1);
				for (int c = 0; c < 4; ++c)
				{
					Rotate(2);
					for (int d = 0; d < 4; ++d)
					{
						Rotate(3);
						for (int e = 0; e < 4; ++e)
						{
							Rotate(4);

							if (newboard[0][0][0] == 0 || newboard[4][4][4] == 0) continue;

							queue<tiii> Q;
							bool visited[5][5][5]{};
							Q.push({ 0,0,0 });
							visited[0][0][0] = true;

							int dist = 0;
							while (!Q.empty())
							{
								int qsz = Q.size();
								dist++;
								while (qsz--)
								{
									auto [cz, cy, cx] = Q.front();
									Q.pop();

									for (int dir = 0; dir < 6; ++dir)
									{
										int nz = cz + dz[dir];
										int ny = cy + dy[dir];
										int nx = cx + dx[dir];

										if (OOB(nz, ny, nx) || newboard[nz][ny][nx] == 0 || visited[nz][ny][nx]) continue;
										visited[nz][ny][nx] = true;

										if (nz == 4 && ny == 4 && nx == 4)
										{
											ans = min(ans, dist);
											Q = {};
											qsz = 0;
											break;
										}

										Q.push({ nz, ny, nx });
									}
								}
							}
						}
					}
				}
			}
		}
	} while (next_permutation(permu.begin(), permu.end()));


	if (ans != INF)
		cout << ans;
	else
		cout << -1;


	return 0;
}


// S : 640
// U : 
// T : 
// C :
// Total :
