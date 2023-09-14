#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

struct tPoint
{
    int y;
    int x;
};

// dp[n][L][R] -> n번째 문자열을 칠 때, 가중치의 최솟값.
int dp[100001][10][10]{};
int wtable[10][10]{};

void dfs(int depth, string& str, int LH, int RH, int w)
{
	if (dp[depth][LH][RH])
    {
        if (w < dp[depth][LH][RH])
            dp[depth][LH][RH] = w;
        else
            return;
    }
    else
    {
        dp[depth][LH][RH] = w;
    }

    if (depth >= str.size())
        return;

    int curNum = str[depth] - '0';
    if(curNum != RH)
		dfs(depth + 1, str, curNum, RH, w + wtable[LH][curNum]);
    if(curNum != LH)
		dfs(depth + 1, str, LH, curNum, w + wtable[curNum][RH]);
}


void CalcTable()
{
    map<int, tPoint> m;
    m.insert({ 0, {4,2}});
    m.insert({ 1, {1,1} });
    m.insert({ 2, {1,2} });
    m.insert({ 3, {1,3} });
    m.insert({ 4, {2,1} });
    m.insert({ 5, {2,2} });
    m.insert({ 6, {2,3} });
    m.insert({ 7, {3,1} });
    m.insert({ 8, {3,2} });
    m.insert({ 9, {3,3} });

    for(int s = 0; s < 10; ++s)
    {
	    for(int e = 0; e < 10; ++e)
	    {
            tPoint sp = m.find(s)->second;
            tPoint ep = m.find(e)->second;
            int x = abs(sp.x - ep.x);
            int y = abs(sp.y - ep.y);
            int Min = min(x, y);
            int Max = max(x, y);

            wtable[s][e] = Min * 3 + (Max - Min) * 2;
            if (wtable[s][e] == 0)
                wtable[s][e] = 1;
	    }
    }
}

struct tInfo
{
    int LH;
    int RH;
    int w;
    int depth;
};

int bfs(string& str)
{
    queue<tInfo> Q;
    Q.push({ 4,6,0,0 });

    int Min = INT_MAX;

    // Q에 들어가는 갯수를 생각하자.
    while(!Q.empty())
    {
        auto front = Q.front();
        Q.pop();
        int curDP = min(dp[front.depth][front.LH][front.RH], dp[front.depth][front.RH][front.LH]); // 손이 바뀌어도 결과는 같음
        if (curDP < front.w) continue; // w + 1인 경우를 막음
        if(front.depth == str.size())
        {
            Min = min(Min, front.w);
            continue;
        }

        int next = str[front.depth] - '0';
        
        if(front.RH != next)
        {
            if(front.w + wtable[front.LH][next] < dp[front.depth + 1][next][front.RH]) // dp보다 작을 때만 push
            {
                dp[front.depth + 1][next][front.RH] = front.w + wtable[front.LH][next];
                Q.push({ next, front.RH, front.w + wtable[front.LH][next], front.depth + 1 });
            }
        }
			
        if (front.LH != next)
        {
            if(front.w + wtable[front.RH][next] < dp[front.depth + 1][front.LH][next])
            {
                dp[front.depth + 1][front.LH][next] = front.w + wtable[front.RH][next];
                Q.push({ front.LH, next, front.w + wtable[front.RH][next], front.depth + 1 });
            }
        }
    }

    return Min;
}

// 밑에서부터 생각 -> 기록된 dp는 항상 최소를 보장. 이건 좀 생각하기 힘들다..
int dfs2(int depth, string& str, int LH, int RH)
{
    if (depth == str.size()) return 0;
    if (dp[depth][LH][RH]) return dp[depth][LH][RH];

    int next = str[depth] - '0';
    int valL = INT_MAX;
    int valR = INT_MAX;
    if (LH != next)
        valL = dfs2(depth + 1, str, LH, next) + wtable[RH][next];
    if (RH != next)
        valR = dfs2(depth + 1, str, next, RH) + wtable[LH][next];

    dp[depth][LH][RH] = min(valL, valR);
    return dp[depth][LH][RH];
}

int solution(string numbers)
{
    int answer = INT_MAX;

    for (int i = 0; i < 9; ++i)
        CalcTable();

    // dfs
    // dfs(0, numbers, 4, 6, 0);

    // dfs2
    answer = dfs2(0, numbers, 4, 6);

    // bfs
    //for (int i = 1; i <= numbers.size(); ++i)
    //    for (int j = 0; j < 10; ++j)
    //        for (int k = 0; k < 10; ++k)
    //            dp[i][j][k] = INT_MAX;
    //answer = bfs(numbers);

    return answer;
}

int main()
{
    string str;
    cin >> str;

    cout << solution(str);

    return 0;
}