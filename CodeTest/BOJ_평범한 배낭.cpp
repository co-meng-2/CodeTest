#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<pii> items(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> items[i].first;     // w
        cin >> items[i].second;    // v
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i-1][j]);
            if (j >= items[i].first)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - items[i].first] + items[i].second);
        }
    }

    cout << dp[n][k];

    return 0;
}