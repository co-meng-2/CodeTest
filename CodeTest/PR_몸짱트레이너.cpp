#include <vector>
#include <unordered_set>

using namespace std;
using pii = pair<int, int>;

int mulx[4] = { 1,-1};
int muly[4] = { 1,1};

int bsz;
int mxDist;
int mxPeople;

bool OOB(int y, int x)
{
    return y < 0 || y >= bsz || x < 0 || x >= bsz;
}

struct HASH {
    size_t operator()(const pair<int, int>& x) const {
        return hash<long long>()(((long long)x.first) ^
            (((long long)x.second) << 32));
    }
};

void dfs(pii cur, unordered_set<pii, HASH>& sel, int& dist, bool& bCan)
{
    if (sel.size() == mxPeople)
    {
        bCan = true;
        return;
    }

    for (int dy = 0; dy <= dist; ++dy)
    {
        int dx = dist - dy;
        bool ok2 = false;
        for (int i = 0; i < 2; ++i)
        {
            int ny = cur.first + dy * muly[i];
            int nx = cur.second + dx * mulx[i];
            if (OOB(ny, nx)) continue;
            if (sel.find({ ny,nx }) != sel.end()) continue;
            bool ok = true;
            for (auto [sely, selx] : sel)
            {
                if (abs(sely - ny) + abs(selx - nx) < dist)
                {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;


            sel.insert({ ny, nx });
            dfs({ ny, nx }, sel, dist, bCan);
            sel.erase(sel.find({ ny,nx }));
            ok2 = true;
            break;
        }
        if (ok2) break;
    }
}




bool check(int mid)
{
    pii s{ 0,0 };
    unordered_set<pii, HASH> sel;
    sel.insert({ 0,0 });
    bool bCan = false;
    dfs(s, sel, mid, bCan);
    return bCan;
}


int solution(int n, int m, vector<vector<int>> timetable) {
    int answer = 0;

    // 10명간 거리 계산 45
    // 100만에 배치 100만c10 -> 개높음
    // 한 점에서 거리가 x이상인 점 들이 k-1개 있는지 확인 -> 안됨.
    // greedy, 이분탐색, sweeping
    bsz = n;
    mxDist = n * 2 - 2;

    vector<int> sweep(722, 0);
    for (auto& it : timetable)
    {
        auto s = it[0] - 600;
        auto e = it[1] - 600;
        sweep[s]++;
        sweep[e + 1]--;
    }

    mxPeople = sweep[0];
    for (int i = 1; i < sweep.size(); ++i)
    {
        sweep[i] += sweep[i - 1];
        mxPeople = max(mxPeople, sweep[i]);
    }
    if (mxPeople <= 1)
        return 0;


    int lo = 1;
    int hi = mxDist;

    // 14번
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    answer = hi;

    return answer;
}

int main()
{
    solution(1000, 5, { {1140, 1200},{1150, 1200},{1100, 1200},{1210, 1300},{1220, 1280} });
}