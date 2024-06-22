#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct tInfo
{
    int time;
    int temp;
    int on;
    int consume;
};

bool InBound(int t, int t1, int t2)
{
    if (t >= t1 && t <= t2)
        return true;
    return false;
}

int FindDir(int t, int t1, int t2)
{
    // 거리가 먼쪽으로 이동해야 함.
    if (abs(t - t1) > abs(t - t2))
        return -1;
    return 1;
}

int solution(int temp, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 0;

    // 실외온도 . 적절 온도 범위. 유지 전력. 바꾸기 전력. 탑승 유무
    // 1분마다 1도씩 변화
    // dfs + memo? 같은 시간일 때 실내 온도, 에어컨 상태가 같다면 작은 값을 선택해야 함.
    // 그러면 bfs가 낫지 않나?
    temp += 10;
    t1 += 10;
    t2 += 10;

    // 시간, 온도, 온오프
    vector<vector<vector<int>>> memo(onboard.size(), vector<vector<int>>(51, vector<int>(2, INF)));
    queue<tInfo> Q;
    Q.push({ 0, temp, 0, 0 });
    Q.push({ 0, temp, 1, 0 });
    while (!Q.empty())
    {
        auto [cTime, cTemp, cOn, cConsume] = Q.front();
        Q.pop();
        if (cTime == onboard.size())
            continue;

        if (onboard[cTime] == 1 && !InBound(cTemp, t1, t2)) continue;
        if (memo[cTime][cTemp][cOn] > cConsume)
        {
            memo[cTime][cTemp][cOn] = cConsume;
        }
        else
        {
            continue;
        }

        // 켜져있는 경우
        if (cOn)
        {
            int nxt = cTemp + FindDir(cTemp, t1, t2);
            // 범위 안
            if (InBound(cTemp, t1, t2))
            {
                // 대기 / 움직임(최선), onoff 
                Q.push({ cTime + 1, nxt, cOn, cConsume + a });
                Q.push({ cTime + 1, nxt, cOn - 1, cConsume + a });
                Q.push({ cTime + 1, cTemp, cOn, cConsume + b });
                Q.push({ cTime + 1, cTemp, cOn - 1, cConsume + b });
            }
            // 범위 밖
            else
            {
                // 움직임 (최선), onoff
                Q.push({ cTime + 1, nxt, cOn, cConsume + a });
                Q.push({ cTime + 1, nxt, cOn - 1, cConsume + a });
            }
        }
        // 꺼져 있는 경우
        else
        {
            // 실외온도 방향으로 움직임, onoff
            if (cTemp == temp)
            {
                Q.push({ cTime + 1, cTemp, cOn, cConsume });
                Q.push({ cTime + 1, cTemp, cOn + 1, cConsume });
            }
            else
            {
                int nxt = cTemp > temp ? cTemp - 1 : cTemp + 1;
                Q.push({ cTime + 1, nxt, cOn, cConsume });
                Q.push({ cTime + 1, nxt, cOn + 1, cConsume });
            }
        }
    }

    int ret = INF;
    for (const auto& it : memo[onboard.size()-1])
    {
        for (const auto& it2 : it)
        {
            ret = min(ret, it2);
        }
    }
    answer = ret;

    return answer;
}
int solution1(int temp, int t1, int t2, int a, int b, vector<int> onboard);

int main()
{
    solution1(28, 18, 26, 10, 8, {0, 0, 1, 1, 1, 1, 1});
	//solution1(-10, -5, 5,5,1,{0,0,0,0,0,1,0});
	return 0;
}

// 이게 훨씬 빠르다.
int solution1(int temp, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 0;

    temp += 10;
    t1 += 10;
    t2 += 10;

    // 시간, 온도
    vector<vector<int>> dp(onboard.size(), vector<int>(51, INF));
	dp[0][temp] = 0;
	for (int i = 1; i < onboard.size(); ++i)
	{
		for (int j = 0; j <= 50; ++j)
		{
			// i k 가 i-1 k-1 ~ k+1에서 어디로가는지 판단.
			if (onboard[i] == 1 && (j < t1 || j > t2)) continue;
			if (j - 1 >= 0 && dp[i - 1][j - 1] != INF)
			{
				// 실외 방향이 +
				if (temp > j - 1)
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);

				// 실내 방향이 + 가능
				if (j - 1 < t2)
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a);
			}
			if (dp[i - 1][j] != INF)
			{
				// 온도 유지
				if (j <= t2 && j >= t1)
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + b);

				// 실외 온도와 같음
				if (j == temp)
					dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			if (j + 1 <= 50 && dp[i - 1][j + 1] != INF)
			{
				// 실외 방향이 -
				if (temp < j + 1)
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);

				// 실내 방향이 - 가능
				if (j + 1 > t1)
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + a);
			}

		}
	}
    answer = *min_element(dp[onboard.size() - 1].begin(), dp[onboard.size() - 1].end());

    return answer;
}