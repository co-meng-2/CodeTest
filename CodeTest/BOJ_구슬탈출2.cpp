#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

// 4^10 = 100만

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0, 1,-1 };
char dirs[4] = { 'D','U','R','L' };


unordered_set<int> visited;
char board[10][10]{};
int ans = 1e9;
string ansPath = "";
void dfs(pii r, pii b, int cnt, string& path) 
{
	for (int i = 0; i < 4; ++i, path.pop_back())
	{
		path += dirs[i];
		pii front = r;
		pii back = b;
		bool swapped = false;
		int yvec = back.first - front.first;
		int xvec = back.second - front.second;
		if ((yvec != 0 && yvec / abs(yvec) == dy[i]) || (xvec != 0 && xvec / abs(xvec) == dx[i]))
		{
			swap(front, back);
			swapped = true;
		}

		bool rEnd = false;
		bool bEnd = false;
		int nfy = front.first;
		int nfx = front.second;
		while (true)
		{
			nfy += dy[i];
			nfx += dx[i];
			if (board[nfy][nfx] == '#')
			{
				nfy -= dy[i];
				nfx -= dx[i];
				break;
			}
			else if (board[nfy][nfx] == 'O')
			{
				if (swapped)
					bEnd = true;
				else
					rEnd = true;

				nfy = -1;
				nfx = -1;

				break;
			}
		}

		if (bEnd)
			continue;

		int nby = back.first;
		int nbx = back.second;
		while (true)
		{
			nby += dy[i];
			nbx += dx[i];
			if (board[nby][nbx] == '#' || (nby == nfy && nbx == nfx))
			{
				nby -= dy[i];
				nbx -= dx[i];
				break;
			}
			else if (board[nby][nbx] == 'O')
			{
				if (swapped)
					rEnd = true;
				else
					bEnd = true;
				break;
			}
		}

		if (bEnd)
			continue;
		else if (rEnd)
		{
			if (ans > cnt)
			{
				ans = cnt;
				ansPath = path;
			}
		}
		else
			if (swapped)
			{
				dfs({ nby, nbx }, { nfy, nfx }, cnt + 1, path);
			}
			else
			{
				dfs({ nfy, nfx }, { nby, nbx }, cnt + 1, path);
			}
	}
}

struct tInfo
{
	pii r;
	pii b;
	int cnt;
};

int main()
{

	fastio;

	int row, col;
	cin >> row >> col;

	pii rPos;
	pii bPos;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 'R') rPos = { i, j };
			else if (board[i][j] == 'B') bPos = { i, j };
		}

	queue<tInfo> Q;
	Q.push({ rPos,bPos, 1 });
	visited.insert(rPos.first * 1000 + rPos.second * 100 + bPos.second * 10 + bPos.first);

	while(!Q.empty())
	{
		auto [r, b, cnt] = Q.front();
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			pii front = r;
			pii back = b;
			bool swapped = false;
			int yvec = back.first - front.first;
			int xvec = back.second - front.second;
			if ((yvec != 0 && yvec / abs(yvec) == dy[i]) || (xvec != 0 && xvec / abs(xvec) == dx[i]))
			{
				swap(front, back);
				swapped = true;
			}

			bool rEnd = false;
			bool bEnd = false;
			int nfy = front.first;
			int nfx = front.second;
			while (true)
			{
				nfy += dy[i];
				nfx += dx[i];
				if (board[nfy][nfx] == '#')
				{
					nfy -= dy[i];
					nfx -= dx[i];
					break;
				}
				else if (board[nfy][nfx] == 'O')
				{
					if (swapped)
						bEnd = true;
					else
						rEnd = true;

					nfy = -1;
					nfx = -1;

					break;
				}
			}

			if (bEnd)
				continue;

			int nby = back.first;
			int nbx = back.second;
			while (true)
			{
				nby += dy[i];
				nbx += dx[i];
				if (board[nby][nbx] == '#' || (nby == nfy && nbx == nfx))
				{
					nby -= dy[i];
					nbx -= dx[i];
					break;
				}
				else if (board[nby][nbx] == 'O')
				{
					if (swapped)
						rEnd = true;
					else
						bEnd = true;
					break;
				}
			}

			if (bEnd)
				continue;
			else if (rEnd)
			{
				cout << cnt;
				return 0;
			}
			else
				if (swapped)
				{
					int hashval = nby * 1000 + nbx * 100 + nfy * 10 + nfx;
					if (visited.find(hashval) == visited.end())
						visited.insert(hashval);
					else
						continue;
					Q.push({ { nby, nbx }, { nfy, nfx }, cnt + 1 });
				}
				else
				{
					int hashval = nfy * 1000 + nfx * 100 + nby * 10 + nbx;
					if (visited.find(hashval) == visited.end())
						visited.insert(hashval);
					else
						continue;
					Q.push({ { nfy, nfx }, { nby, nbx }, cnt + 1 });
				}
		}
	}

	cout << "-1";

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :