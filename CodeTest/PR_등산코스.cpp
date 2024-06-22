#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    // sort(gates.begin(), gates.end());
    sort(summits.begin(), summits.end());
    // set<int> s;
    set<int> g;

    // gate 판정용
    for (auto gate : gates)
        g.insert(gate);

    // BFS에서 쓸 인접 리스트
    vector<vector<pii>> adjList(n + 1);
    for (const auto& path : paths)
    {
        adjList[path[0]].push_back({ path[2], path[1] });
        adjList[path[1]].push_back({ path[2], path[0] });
    }

    // 둘 다 min값 가져야하기에 INF로
    answer = { INF, INF };

    // 최소 intensity
    vector<int> table(n + 1, INF);

    // summit 방문하지 않게 table 작업 (기존에 set로 찾았는데 이게 더 좋을듯)
    for (auto summit : summits)
        table[summit] = 0;


    for (const auto& summit : summits)
    {
        queue<pii> Q;
        Q.push({ 0, summit });

        // summit에서부터 BFS 출발
        while (!Q.empty())
        {
            auto [curw, cur] = Q.front();
            Q.pop();

            for (const auto& [w, d] : adjList[cur])
            {
                int nw = max(curw, w); // 다음 최소 intensity
                if (table[d] <= nw) continue;

                // if (s.find(d) != s.end()) continue;
                table[d] = nw;
                if (g.find(d) != g.end()) // gate 판정
                {
                    if (answer[1] > nw) // summit 이미 정렬 -> 작은 값의 summit부터 시작 
                    {
                        answer[0] = summit;
                        answer[1] = nw;
                    }
                    continue;
                }
                Q.push({ nw, d });
            }
        }
    }

    return answer;
}