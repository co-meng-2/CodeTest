#include <functional>
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
#include <unordered_set>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1};

vector<vector<int>>ans{ {1, 2, 3}, { 4,5,6 }, { 7,8,0 } };


bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= 3 || x >= 3;
};

int to_strint(vector<vector<int>>& board)
{
	int sum = 0;
	int mul = 1;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			sum += board[i][j] * mul;
			mul *= 10;
		}
	return sum;
}

bool check(vector<vector<int>>& cmp)
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (cmp[i][j] != ans[i][j]) return false;

	return true;
}

struct tInfo
{
	vector<vector<int>> board;
	pii zPos;
	int cnt;
};

int main()
{
	fastio;

	pii zPos;
	vector<vector<int>> board(3, vector<int>(3));
	set<int> visited;

	pii idxs[9]{};
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				zPos = { i,j };
		}

	visited.insert(to_strint(board));

	queue<tInfo> Q;
	Q.push({ board, zPos, 0 });
	while(!Q.empty())
	{
		auto& [b, z, c] = Q.front();

		if(check(b))
		{
			cout << c;
			return 0;
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = z.first + dy[i];
			int nx = z.second + dx[i];

			if (OOB(ny, nx)) continue;
			swap(b[ny][nx], b[z.first][z.second]);
			int elem = to_strint(b);
			if (visited.find(elem) == visited.end())
			{
				visited.insert(elem);
				Q.push({ b, {ny, nx}, c + 1 });
			}
			swap(b[ny][nx], b[z.first][z.second]);
		}
		Q.pop();
	}
	cout << -1;
	return 0;
}


// S : 956
// U : 
// T : 
// C :
// Total :