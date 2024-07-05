#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

const int MAX = 1e9;
int n;

vector<int> nums;
vector<pii> lis;
vector<pii> change;
vector<pii> ans;
bool finish = false;
void dfs(int cur, int cnt)
{
    if (cnt == 4 || finish) return;
    if (cur == n)
    {
        finish = true;
        ans = change;
        return;
    }

    int num = nums[cur];
    int back = lis.back().second;

    if (num < back)
    {
        lis.push_back({ cur, back });
        change.push_back({ cur, back });
        dfs(cur + 1, cnt + 1);
        lis.pop_back();
        change.pop_back();

        auto cpy = lis;
        auto cpy2 = change;

        int changeCnt = cnt;
        int prev = num;

        bool bCan = true;

        for (int i = lis.size() - 1; i >= 0; --i)
        {
            if (lis[i].second > prev)
            {
                lis[i].second = prev;

                bool bFind = false;
                for (auto& [idx, val] : change)
                {
                    if (idx == lis[i].first)
                    {
                        val = prev;
                        bFind = true;
                        break;
                    }
                }

                if (!bFind)
                {
                    change.push_back({ lis[i].first, prev });
                    changeCnt++;
                    if (changeCnt == 4)
                    {
                        bCan = false;
                        break;
                    }
                }
            }
            else
                break;
        }

        if (bCan)
        {
            lis.push_back({ cur, num });
            dfs(cur + 1, changeCnt);
        }
        lis = cpy;
        change = cpy2;
    }
    else
    {
        lis.push_back({ cur, num });
        dfs(cur + 1, cnt);
        lis.pop_back();
    }
}

int main()
{
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    lis.push_back({ 0, nums[0] });

    dfs(1, 0);
    sort(ans.begin(), ans.end());
    if (finish)
    {
        cout << "YES\n" << ans.size() << "\n";
        for (auto [idx, val] : ans)
            cout << idx + 1 << " " << val << "\n";
    }
    else
        cout << "NO";

    return 0;
}