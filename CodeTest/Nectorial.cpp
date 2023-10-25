#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <climits>
#include <iostream>

using namespace std;

struct tPos
{
    int y;
    int x;
};

int board[100000][3]{};
int minimumMovement(vector<int> obstacleLanes)
{
    // dfs 2^100000 X

    int rowCnt = obstacleLanes.size();
    for (int i = 0; i < rowCnt; ++i)
    {
        board[rowCnt - 1 - i][obstacleLanes[i] - 1] = 1;
    }

    tPos cPos = { rowCnt - 1, 1 };

    int ans = 0;
    while (true)
    {
        // go straight
        while (cPos.y >= 0 && board[cPos.y][cPos.x] != 1)
        {
            cPos.y--;
        }

        if (cPos.y < 0)
            break;

        int maxLane = -1;
        int maxDist = -1;
        for (int i = 0; i < 3; ++i)
        {
            if (i == cPos.x) continue;

            tPos nPos = cPos;
            nPos.y -= 1;

            int dist = 0;
            while (nPos.y >= 0 && board[nPos.y][i] != 1)
            {
                nPos.y--;
                dist++;
            }

            if (maxDist < dist)
            {
                maxDist = dist;
                maxLane = i;
            }
        }

        cPos.x = maxLane;
        ans++;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ob;
    int k;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        ob.push_back(k);
    }

    int a = minimumMovement(ob);
    return 0;
}