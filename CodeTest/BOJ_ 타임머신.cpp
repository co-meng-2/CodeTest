#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int floyd[501][501]{};

int main()
{
    fastio;

    memset(floyd, INF, sizeof(floyd));

    int n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int s, d, w;
        cin >> s >> d >> w;
        floyd[s][d] = min(floyd[s][d],w);
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (floyd[i][k] != INF && floyd[k][j] != INF)
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }

    for (int i = 1; i <= n; ++i)
        if (floyd[i][i] < 0 && floyd[1][i] != INF)
        {
            cout << -1;
            return 0;
        }

    for (int i = 2; i <= n; ++i)
    {
        if (floyd[1][i] == INF)
            cout << -1;
        else
            cout << floyd[1][i];
        cout << "\n";
    }

    return 0;
}