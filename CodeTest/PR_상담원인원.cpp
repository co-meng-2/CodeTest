#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

void dfs(int r, vector<int>& mentoCnt, vector<queue<pii>>& vecQ, int& mn, int curIdx = 1)
{
    // mentoCnt size는 k+1
    if (curIdx == mentoCnt.size())
    {
        int waitTime = 0;
        for (int i = 1; i < vecQ.size(); ++i)
        {
            auto Q = vecQ[i];
            priority_queue<int, vector<int>, greater<>> PQ; // 끝나는 시간 작은 순

            while (!Q.empty())
            {
                auto [s, w] = Q.front();
                Q.pop();

                if (PQ.size() < mentoCnt[i] + 1)
                    PQ.push(s + w);
                else
                {
                    auto top = PQ.top();
                    PQ.pop();
                    if (s < top)
                    {
                        waitTime += top - s;
                        PQ.push(top + w);
                    }
                    else
                        PQ.push(s + w);
                }
            }
        }
        mn = min(mn, waitTime);
        return;
    }

    for (int i = 0; i <= r; ++i)
    {
        mentoCnt[curIdx] += i;
        dfs(r - i, mentoCnt, vecQ, mn, curIdx + 1);
        mentoCnt[curIdx] -= i;
    }
}

int solution(int k, int n, vector<vector<int>> reqs/*시각, 시간, 유형, 시각 기준 오름차순 정렬, 시각 중복X*/) {
    int answer = 0;
    // 참가자의 대기시간을 최소로 멘토에게 유형을 분배
    // 각 유형별로 멘토 한 명 이상
    // reqs는 queue로 만들 수 있음.
    // n-k를 k개로 나누는 경우의 수 15를 5개로 나누는 경우의 수
    // 중복 조합 뽑을 수 있는 5가지를 15번 중복을 허용해서 뽑는다 칸막이 4개와 뽑을 것 15 -> 19C5 = 대충 만?

    // queue만들기
    vector<queue<pii>> vecQ(k + 1);
    for (auto req : reqs)
    {
        vecQ[req[2]].push({ req[0], req[1] });
    }

    vector<int> mentoCnt(k + 1, 0);
    int mn = 1e9;
    dfs(n - k, mentoCnt, vecQ, mn);
    answer = mn;


    return answer;
}

int main()
{
    solution(2, 3, { {5, 55, 2},{10, 90, 2},{20, 40, 2},{50, 45, 2},{100, 50, 2} });
    return 0;
}