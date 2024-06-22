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
#include <memory>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

enum EColor
{
	W,
	R,
	B
};

struct tStack
{
	vector<int> pawns;
	int y;
	int x;
};

int board[14][14]{};
int stboard[14][14]{};
int main()
{
	fastio;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i <= N+1; ++i)
		for (int j = 0; j <= N+1; ++j)
		{
			if (i == 0 || j == 0 || i == N+1 || j == N+1)
			{
				board[i][j] = B;
				continue;
			}
				
			cin >> board[i][j];
		}
	memset(stboard, -1, sizeof(stboard));

	vector<pii> dirs(K);
	vector<tStack> stacks(K);
	for(int i = 0; i < K; ++i)
	{
		int y, x;
		cin >> y >> x;
		stboard[y][x] = i;
		stacks[i].y = y;
		stacks[i].x = x;
		stacks[i].pawns.push_back(i);
		int dir;
		cin >> dir;
		dirs[i] = {dy[dir - 1], dx[dir - 1]};
	}

	// 흰 -> 칸으로 이동 가장 위에 A를 올림
	// 빨 -> 칸으로 이동 A의 순서를 바꿔서 올림
	// 파 -> 방향 반대로 함 -> 이동 -> 또 파면 움직이지 않음

	int cnt = 0;
	while (true)
	{
		cnt++;
		for (int i = 0; i < K; ++i)
		{
			
			int curStIdx = -1;
			for (int j = 0; j < stacks.size(); ++j)
				for (auto it : stacks[j].pawns)
					if (it == i)
					{
						curStIdx = j;
						j = stacks.size();
						break;
					}

			auto& [pawns, y, x] = stacks[curStIdx];
			int& front = pawns.front();
			if (front != i) continue;

			int ny = y + dirs[front].first;
			int nx = x + dirs[front].second;

			if (board[ny][nx] == B)
			{
				dirs[front].first *= -1;
				dirs[front].second *= -1;

				ny += 2 * dirs[front].first;
				nx += 2 * dirs[front].second;
			}

			if (board[ny][nx] == W)
			{
				stboard[y][x] = -1;
				if (stboard[ny][nx] < 0)
				{
					stboard[ny][nx] = curStIdx;
					y = ny;
					x = nx;
				}
				else
				{
					stacks[stboard[ny][nx]].pawns.insert(stacks[stboard[ny][nx]].pawns.end(), stacks[curStIdx].pawns.begin(), stacks[curStIdx].pawns.end());
					stacks[curStIdx].pawns.clear();

					if (stacks[stboard[ny][nx]].pawns.size() >= 4)
					{
						cout << cnt;
						return 0;
					}
				}
			}
			else if (board[ny][nx] == R)
			{
				reverse(stacks[curStIdx].pawns.begin(), stacks[curStIdx].pawns.end());
				stboard[y][x] = -1;
				if (stboard[ny][nx] < 0)
				{
					stboard[ny][nx] = curStIdx;
					y = ny;
					x = nx;
				}
				else
				{
					stacks[stboard[ny][nx]].pawns.insert(stacks[stboard[ny][nx]].pawns.end(), stacks[curStIdx].pawns.begin(), stacks[curStIdx].pawns.end());
					stacks[curStIdx].pawns.clear();

					if(stacks[stboard[ny][nx]].pawns.size() >= 4)
					{
						cout << cnt;
						return 0;
					}
				}
			}

			if(cnt > 1000)
			{
				cout << -1;
				return 0;
			}
		}
	}


	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :