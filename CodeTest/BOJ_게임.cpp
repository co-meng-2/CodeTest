#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <set>
#include <string>
// cycle 판정
// 그래프 만들어서 최대 depth

bool bFindCycle = false;
// 가장 큰 깊이를 반환
int dfs(int cur, vector<vector<int>>& adjList, std::set<int>& cycleIdxs, vector<int>& dp)
{
	if (adjList[cur].empty())
		return 1;

	if (dp[cur] != -1)
		return dp[cur];

	cycleIdxs.insert(cur);

	int maxDepth = -1;
	for (int i = 0; i < adjList[cur].size(); ++i)
	{
		if (cycleIdxs.find(adjList[cur][i]) != cycleIdxs.end())
		{
			bFindCycle = true;
			return -1;
		}

		maxDepth = std::max(maxDepth, dfs(adjList[cur][i], adjList, cycleIdxs, dp));
	}

	cycleIdxs.erase(cur);
	return dp[cur] = maxDepth + 1;
}

int main()
{
	fastio;

	int col, row;
	cin >> row >> col;
	vector<vector<int>> board(row, vector<int>(col));

	for (int i = 0; i < row; ++i)
	{
		std::string str;
		cin >> str;
		int idx = 0;
		for (auto it = str.begin(); it != str.end(); ++it)
		{
			int tmp = *it - '0';
			board[i][idx] = tmp;
			if (board[i][idx] > 9) board[i][idx] = -1;
			idx++;
		}
	}

	vector<vector<int>> adjList(col * row);

	std::pair<int, int> dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (board[i][j] == -1) continue;

			for (int k = 0; k < 4; ++k)
			{
				int nRow = i + board[i][j] * dir[k].first;
				int nCol = j + board[i][j] * dir[k].second;
				if (nRow >= 0 && nRow < row && nCol >= 0 && nCol < col && board[nRow][nCol] != -1)
				{
					adjList[i * col + j].push_back(nRow * col + nCol);
				}
			}
		}
	}


	
	std::set<int> cycleIdxs;
	vector<int> dp(row * col, -1);

	
	int ans = dfs(0, adjList, cycleIdxs, dp);

	if (bFindCycle)
		cout << -1;
	else
		cout << ans;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :