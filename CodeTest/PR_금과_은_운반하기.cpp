#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{
    long long answer = -1;
    int len = g.size();

    // time
    ll lo = 0;
    ll hi = 1e15;

    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll maxsubg = 0;
        ll maxsubs = 0;
        ll maxsuball = 0;
        bool possible = false;
        for (int i = 0; i < len; ++i)
        {
            ll cnt = 0;
            if (t[i] <= mid)
                cnt = 1 + (mid - t[i]) / (2 * t[i]);
            ll amount = cnt * w[i];

            maxsubg += min(amount, (ll)g[i]);
            maxsubs += min(amount, (ll)s[i]);
            maxsuball += min(amount, (ll)g[i] + s[i]);
            if (maxsuball >= a + b && maxsubg >= a && maxsubs >= b)
            {
                possible = true;
            }
        }
        if (possible)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    answer = lo;

    return answer;
}
