#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>
#include <random>

using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

//int mnCosts[151][151]{};
//bool visited[151][151][301]{};
//int mn = 1e9;
//int mxalp;
//int mxcop;
//
//void dfs(vector<vector<int>>& problems, int alp, int cop, int cost)
//{
//    // 같은  alp cop에 더 낮은 cost가 true라면
//
//    if (alp >= mxalp && cop >= mxcop)
//    {
//        mn = min(mn, cost);
//        return;
//    }
//
//    for (const auto& p : problems)
//    {
//        int areq = p[0];
//        int creq = p[1];
//        int arwd = p[2];
//        int crwd = p[3];
//        int pcost = p[4];
//
//        // 문제 못 품
//        if (areq > alp || creq > cop) continue;
//        int nalp = alp + arwd;
//        int ncop = cop + crwd;
//        int ncost = cost + pcost;
//        if (ncost > 300) continue;
//
//        if (nalp > 150) nalp = 150;
//        if (ncop > 150) ncop = 150;
//
//        if (visited[nalp][ncop][ncost]) continue;
//        if (mnCosts[nalp][ncop] <= ncost) continue;
//        else mnCosts[nalp][ncop] = ncost;
//
//        visited[nalp][ncop][ncost] = true;
//
//        dfs(problems, nalp, ncop, ncost);
//    }
//}

int solution(int alp, int cop, vector<vector<int>> pr) {
    int answer = 0;

    int mn = 1e9;
    int mxalp = -1;
    int mxcop = -1;

    // problems.push_back({ 0,0,1,0,1 });
    // problems.push_back({ 0,0,0,1,1 });

    // test용 코드 배열에서는 상관없지만 vector에서는 반드시 auto& 를 쓰자.
    int problems[102][5];
    for (int i = 0; i < pr.size(); ++i)
        for (int j = 0; j < pr[i].size(); ++j)
            problems[i][j] = pr[i][j];

    for (auto p : problems)
    {
        mxalp = max(p[0], mxalp);
        mxcop = max(p[1], mxcop);
    }

    vector<vector<int>> table(151, vector<int>(151, 1e9));
    queue<tiii> Q;
    Q.push({ alp, cop, 0 });
    table[alp][cop] = 0;
    while (!Q.empty())
    {
        auto [calp, ccop, ccost] = Q.front();
        Q.pop();

        for (const auto p : problems)
        {
            int areq = p[0];
            int creq = p[1];
            int arwd = p[2];
            int crwd = p[3];
            int cost = p[4];

            if (areq > calp || creq > ccop) continue;

            int nalp = calp + arwd;
            int ncop = ccop + crwd;
            if (nalp > 150) nalp = 150;
            if (ncop > 150) ncop = 150;

            int ncost = ccost + cost;
            if (ncost > 300) continue;
            if (table[nalp][ncop] <= ncost) continue;
            table[nalp][ncop] = ncost;
            Q.push({ nalp, ncop, ncost });
        }
    }

    for (int i = mxalp; i <= 150; ++i)
    {
        for (int j = mxcop; j <= 150; ++j)
        {
            mn = min(mn, table[i][j]);
        }
    }

    answer = mn;
    return answer;
}

int main()
{
    // 시드값을 얻기 위한 random_device 생성.
    std::random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    std::mt19937 gen(rd());

    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    uniform_int_distribution<int> dis(0, 150);
    uniform_int_distribution<int> dis2(0, 30);
    uniform_int_distribution<int> dis3(1, 100);

    for (int i = 0; i < 100; ++i)
    {
        vector<vector<int>> test;
        test.push_back({ 0,0,1,0,1 });
        test.push_back({ 0,0,1,1,1 });
        for (int j = 0; j < 100; ++j)
        {
            test.push_back({ dis(gen), dis(gen), dis2(gen), dis2(gen), dis3(gen) });
        }
        vector<vector<int>> k(1000000, vector<int>(5));
        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        for(auto& it : k)
        {
            
        }
        // solution(0, 0, test);
        std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;
        std::chrono::system_clock::time_point start1 = std::chrono::system_clock::now();
        for (auto it : k)
        {

        }
        // solution(0, 0, test);
        std::chrono::duration<double>sec1 = std::chrono::system_clock::now() - start;
        
        cout << "auto & : " <<sec.count() << "\n" << "auto : " << sec1.count() << "\n" << "\n";
    }
}