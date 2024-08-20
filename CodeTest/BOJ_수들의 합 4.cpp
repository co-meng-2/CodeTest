#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)


#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include <cmath>
#include <unordered_map>
#include <string_view>
#include <queue>
#include <stack>
#include <numeric>
#include <set>
#include <memory>
#include <cstring>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ti3 = tuple<int, int, int>;
using ti4 = tuple<int, int, int, int>;
using ti5 = tuple<int, int, int, int, int>;
#define all(x) x.begin(), x.end()
#define Call(x) begin(x),end(x)
constexpr int INF = 1e9;
constexpr ll LINF = 1e18;

int n, k;
int arr[200'001];
int main()
{
    fastio;
    cin >> n >> k;
    map<int, ll> hash;
    ll cnt = 0;
    hash[0] = 1; // 아무것도 안 빼는 경우의 수
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        arr[i] = arr[i - 1] + temp;
        cnt += hash[arr[i] - k];
        hash[arr[i]]++;
    }
    cout << cnt;
    return 0;
}