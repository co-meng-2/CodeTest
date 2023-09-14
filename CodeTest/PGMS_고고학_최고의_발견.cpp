#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

// 하나의 시계에 하나의 시곗바늘
// 한 번의 조작 -> 90도
// 상하좌우로 인접한 시계도 같이 돌아감
// 모서리는 3개 꼭짓점은 2개 돌아감
// 모든 시곗바늘이 12시를 가리키면 끝
// 최소 조작 횟수를 구하라!
// clockhands length : 2 - 8 element 0 - 3
// 0이 12시 1이 3시 2는 6시 3은 9시
// 해결 가능한 퍼즐만 주어짐
// 정사각형

// 같은 자리를 4번까지 돌릴 것
// 4^64 = 2^128 완전탐색으로는 안됨.
// 백트래킹 해야되는데 그 방식은 대각선으로 탐색하는 것

struct tPoint
{
    int y;
    int x;
};

vector<vector<tPoint>> vecP;
int puzzleSize = 0;
tPoint arr[5] = { {0,0},{-1,0}, {0,1}, {1,0}, {0,-1} };


void Rotate(vector<vector<int>>& pz, int col, int row, bool reverse = false)
{
	for(int i = 0; i < 5; ++i)
	{
        int curCol = col + arr[i].y;
        int curRow = row + arr[i].x;

        if(curCol >= 0 && curCol < pz.size() && curRow >= 0 && curRow < pz.size())
        {
			pz[curCol][curRow]++;
			if (pz[curCol][curRow] == 4)
				pz[curCol][curRow] = 0;
        }
	}
}

int ANS = INT_MAX;
void dfs(int depth, vector<vector<int>>& pz, int curIdx, int level, vector<tPoint>& vecPrev, int ans)
{
	tPoint curP = vecP[level][curIdx];

	if (depth == puzzleSize * puzzleSize)
	{
		if (pz[curP.y][curP.x] == pz[curP.y][curP.x-1] && pz[curP.y-1][curP.x] == pz[curP.y][curP.x])
		{
			if (pz[curP.y][curP.x] == 1) ans += 3;
			else if (pz[curP.y][curP.x] == 2) ans += 2;
			else if (pz[curP.y][curP.x] == 3) ans += 1;
			ANS = min(ans, ANS);
		}
			
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		Rotate(pz, curP.y, curP.x);
		ans++;
		if (i == 3)
			ans -= 4;

		// 도달했을 때
		if (curIdx + 1 == vecP[level].size())
		{
			curIdx = -1;
			level++;
		}

		if (curP.y == 0)
		{
			dfs(depth + 1, pz, curIdx + 1, level, vecP[level - 1], ans);
		}
		// curP의 위 요소가 12시일 때
		else if (pz[curP.y - 1][curP.x] == 0)
		{
			if (curP.x > 0 && curIdx == -1 && pz[curP.y][curP.x - 1] != 0) continue;
				
			dfs(depth + 1, pz, curIdx + 1, level, vecP[level - 1], ans);
		}
	}
}

int solution(vector<vector<int>> clockHands) {
	int answer = 0;
	int n = clockHands.size();
	vecP.resize(n * 2 - 1);

	// i는 대각선 갯수
	for(int i =0; i<n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			vecP[i + j].push_back({ i, j });
		}
	}

	puzzleSize = clockHands.size();
	dfs(1, clockHands, 0, 0, vecP[0], 0);
	answer = ANS;
    return answer;
}

int main()
{
	vector<vector<int>> clockHands =
	{
		{ 0,3 },
		{ 3,3 },
	};

	cout << solution(clockHands);

	return 0;
}

// TC
// { 0,3,3,0 },
// { 3,2,2,3 },
// { 0,3,2,0 },
// { 0,3,3,3 },

// { 0,3 },
// { 3,3 },
// { 0,3,2,0 },
// { 0,3,3,3 },