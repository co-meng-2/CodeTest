#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 아래부터 채운다 -> 2 1의 경우에는 위부터 채워야 함.
// 위부터 채워야 한다.
// 위부터 채워서 다 visited를 조사한다?
// 최악의 경우 -> 1 + 2 + 3 + ... 100000 = 50억 정도

// 10 9 8 6 3 2 이렇게 채워진 상태라고 가정.

// dp[i]는 열린 다음 공항
// gi를 받음 -> dp[gi] 값을 받아봄 dp[gi] 값이 음수가 아니라면 그 공항의 dp를 다시 받아 열린 공항을 탐색 + dp[gi]에 이어진 공항을 갱신해준다.
// 음수(열려있다면)라면 그 전(--) 공항으로 값을 갱신.

const int isOpen = -1;
const int isEnd = -2;

// 열려있는 다음 Gate를 재귀적으로 찾는다. 찾은 다음 Gate의 인덱스를 return 한다.
int FindNextGate(int desireMaxGateIdx, vector<int>& dp, int& ans, bool& bExit)
{
	// 최종적으로 도착한 Gate가 닫혀잇음 -> 폐쇄
	if (dp[desireMaxGateIdx] == isEnd)
	{
		bExit = true;
		return isEnd;
	}

	// 최종적으로 도달한 Gate가 열려있음 
	else if (dp[desireMaxGateIdx] == isOpen)
	{
		ans++;
		// 도착한 인덱스가 1 -> 다음 인덱스는 없다.
		if (desireMaxGateIdx == 1)
			return dp[desireMaxGateIdx] = isEnd;
		/// 도착한 인덱스가 1이 아니면 도착한 인덱스에서 1을 빼준 값을 dp에 채워준다.
		else
			return dp[desireMaxGateIdx] = desireMaxGateIdx - 1;
	}

	// dp가 들고 있는 다음 Gate로 가서 판정하기.
	else if (dp[desireMaxGateIdx] > 0)
	{
		dp[desireMaxGateIdx] = FindNextGate(dp[desireMaxGateIdx], dp, ans, bExit);
		return dp[desireMaxGateIdx];
	}
}

int main()
{
	fastio;

	int G, P;
	cin >> G >> P;

	// 비행기가 들어가고자 하는 가장 큰 Gate
	vector<int> desireGateIdx(P+1);
	for (int i = 1; i <= P; ++i)
	{
		cin >> desireGateIdx[i];
	}

	// dp[i]는 desireGateIdx[i]입장에서 열려있다고 생각되는 다음 Gate.
	vector<int> dp(G + 1, -1);
	int ans = 0;		// 출력 정답
	bool bExit = false; // 공항 폐쇄 bool
	for (int i = 1; i <= P; ++i)
	{
		FindNextGate(desireGateIdx[i], dp, ans, bExit);
		if(bExit)
			break;
	}

	cout << ans;

	return 0;
}

// S : 10:37
// U : 10:41
// T : 10:54
// C : 11:21
// Total : 44 min