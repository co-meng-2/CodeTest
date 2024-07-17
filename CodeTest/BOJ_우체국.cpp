#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n;
vector<pii> locs;

int main()
{
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int loc, w;
        cin >> loc >> w;
        locs.push_back({ loc, w });
        sum += w;
    }
    sort(locs.begin(), locs.end());

    ll cur = 0;
    for (auto [loc, w] : locs)
    {
        cur += w;
        if (cur >= (sum + 1) / 2)
        {
            cout << loc;
            break;
        }
    }
    return 0;
}