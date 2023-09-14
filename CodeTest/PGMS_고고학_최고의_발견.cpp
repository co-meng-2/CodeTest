#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

// �ϳ��� �ð迡 �ϳ��� �ð�ٴ�
// �� ���� ���� -> 90��
// �����¿�� ������ �ð赵 ���� ���ư�
// �𼭸��� 3�� �������� 2�� ���ư�
// ��� �ð�ٴ��� 12�ø� ����Ű�� ��
// �ּ� ���� Ƚ���� ���϶�!
// clockhands length : 2 - 8 element 0 - 3
// 0�� 12�� 1�� 3�� 2�� 6�� 3�� 9��
// �ذ� ������ ���� �־���
// ���簢��

// ���� �ڸ��� 4������ ���� ��
// 4^64 = 2^128 ����Ž�����δ� �ȵ�.
// ��Ʈ��ŷ �ؾߵǴµ� �� ����� �밢������ Ž���ϴ� ��

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

		// �������� ��
		if (curIdx + 1 == vecP[level].size())
		{
			curIdx = -1;
			level++;
		}

		if (curP.y == 0)
		{
			dfs(depth + 1, pz, curIdx + 1, level, vecP[level - 1], ans);
		}
		// curP�� �� ��Ұ� 12���� ��
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

	// i�� �밢�� ����
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