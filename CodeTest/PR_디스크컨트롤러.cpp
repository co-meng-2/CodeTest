#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;

struct cmp
{
    bool operator()(pii lhs, pii rhs)
    {
        return lhs.first > rhs.first;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    // 시작할 수 있는 job에서 가장 짧은 job을 수행.

    priority_queue<pii, vector<pii>, cmp> PQ;
    sort(jobs.begin(), jobs.end());
    PQ.push({ jobs[0][1],jobs[0][0]});
    int time = jobs[0][0];
    int idx = 1;
    while (!PQ.empty())
    {
        auto [w, s] = PQ.top();
        PQ.pop();

        answer += w + time - s;
        time += w;

        while(idx < jobs.size() && time >= jobs[idx][0])
        {
            PQ.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }
            
        if(idx < jobs.size() && PQ.empty())
        {
            PQ.push({ jobs[idx][1], jobs[idx][0]});
            time = jobs[idx][0];
            idx++;
        }
    }

    return answer / jobs.size();
}


int main()
{
    solution({ {0, 3},{1, 9},{2, 6} ,{20,21} });
}