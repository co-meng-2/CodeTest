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
using tiiii = tuple<int, int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// 7개를 이은 것 중 s가 더 많은 경우의 수
// 최대 4^7*25 널널함 그냥 완성된 경로를 체크하는 식으로 하면 될듯

// 25C7 

char board[5][5];
unordered_set<int> check;

bool OOB(int y , int x)
{
	return y < 0 || x < 0 || x >= 5 || y >=5;
}

int main()
{
	fastio;

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> board[i][j];

	int ans = 0;
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 5; ++j)
		{
			queue<pii> Q;
			Q.push({ 1 << (i * 5 + j), board[i][j] == 'Y' });
			int step = 1;
			while(!Q.empty())
			{
				int qsz = Q.size();
				step++;

				while (qsz--)
				{
					auto [cpath, ccnt] = Q.front();
					Q.pop();

					for (int k = 0; k < 25; ++k)
					{
						if (!(cpath & (1 << k))) continue; // 방문한데 또 체크 X -> 경로에 여기가 있나

						int cx = k % 5;
						int cy = k / 5;

						for (int dir = 0; dir < 4; ++dir)
						{
							int ny = cy + dy[dir];
							int nx = cx + dx[dir];
							if (OOB(ny, nx)) continue;

							int ncnt = ccnt + (board[ny][nx] == 'Y');
							if (ncnt >= 4) continue;

							int add = 1 << (ny * 5 + nx);
							if (cpath & add) continue; // 또 체크된데 넘기기

							int npath = cpath + add;
							if (check.count(npath)) continue;

							check.insert(npath);

							if (step == 7)
								ans++;
							else
								Q.push({ npath, ncnt });
						}

					}
				}
			}
		}

	cout << ans;

	return 0;
}


// S : 404
// U : 405
// T : 411
// C : 509
// Total : 1h 5min

// Comment
// 일반적인 BFS로는 안 되는 경로 구하기가 있다.
