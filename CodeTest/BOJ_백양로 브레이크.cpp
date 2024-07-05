#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;
const int Big = 10000;

int floyd[251][251];
int n, m, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(floyd, 0x3f, sizeof(floyd));
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int s, d, w;
        cin >> s >> d >> w;
        if (w)
        {
            floyd[s][d] = 1;
            floyd[d][s] = 1;
        }
        else
        {
            floyd[s][d] = 1;
            floyd[d][s] = Big;
        }
    }

    for (int l = 1; l <= n; l++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][l] + floyd[l][j]);

    for (int i = 1; i <= n; i++)
        floyd[i][i] = 0;

    cin >> k;
    while (k--)
    {
        int s, d;
        cin >> s >> d;
        cout << floyd[s][d] / Big << "\n";
    }


    return 0;
}