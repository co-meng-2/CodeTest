#include <iostream>
#include <vector>
#include <algorithm>

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

using namespace std;

int n;

bool visited[101][101]{};

int main()
{
    cin >> n;
    int cnt = 0;
    while (n--)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> dirs{d};
        visited[y][x] = true;

        while (g--)
        {
            int dsz = dirs.size();
            for (int i = dsz - 1; i >= 0; --i)
            {
                dirs.push_back(dirs[i] == 3 ? 0 : dirs[i] + 1);
            }
        }
        for (auto dir : dirs)
        {
            y += dy[dir];
            x += dx[dir];
            if (y >= 0 && x >= 0 && y <= 100 && x <= 100)
                visited[y][x] = true;
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (visited[i][j] &&
                visited[i + 1][j] &&
                visited[i][j + 1] &&
                visited[i + 1][j + 1])
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}