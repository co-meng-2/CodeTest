#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;


// 전체 16! 안됨
// 사이클 가능성
// 사이클이 완성되었다고 생각 -> 그 점에서 어떤 점을 선택해야 하는가?

// 한 점을 정하고 다른 한 점을 정했을 때
// 98 과 89가 같은가? 다를 수 있다.

// 16개에서 2개를 고름 16C2 -> 120 -> x에서 y로 가는 가중치
// 16개에서 3개를 고름 -> 1에서 3으로 -> 본인을 제외한 2개로 3으로 갈 수 있는 것 중, 3으로 갈 수 있는 것 중에서 최솟값을 넣어줌

int adjMat[16][16];

const int INF = 0x3f3f3f3f;
int dp[16][(1 << 16) - 1]{};
int main()
{
	fastio;

	int n;
	cin >> n;

	// 도착 Path
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> adjMat[i][j];
			if (i == j) continue;
			dp[j][ (1 << i) + (1 << j)] = adjMat[i][j];
		}

	for (int bitCnt = 2; bitCnt < n; ++bitCnt)
	{
		vector<bool> permu(n, false);

		for (int k = 0; k < bitCnt; ++k)
			permu[k] = true;

		vector<int> bits;
		do
		{
			int bit = 0;
			for (int i = 0; i < n; ++i)
				if (permu[i])
					bit |= 1 << i;
			bits.push_back(bit);
		} while (prev_permutation(permu.begin(), permu.end()));


		for (int i = 1; i < n; ++i) // 도착
		{
			for (auto bit : bits)
			{
				if (~bit & 1 || ~bit & (1 << i)) continue;
				for (int j = 1; j < n; ++j) // 새로운 도착지
				{
					if(~bit & (1 << j))
					{
						int newBit = bit | (1 << j);
						if(dp[i][bit] != 0 && adjMat[i][j] != 0)
						{
							if(dp[j][newBit] == 0)
								dp[j][newBit] = dp[i][bit] + adjMat[i][j];
							else
								dp[j][newBit] = min(dp[i][bit] + adjMat[i][j], dp[j][newBit]);
						}
					}
				}
			}
		}
	}

	int ans = INF;
	for(int i = 1; i < n; ++i)
	{
		if(dp[i][ (1 << n) - 1] != 0 && adjMat[i][0] != 0)
			ans = min(ans, dp[i][(1 << n) - 1] + adjMat[i][0]);
	}

	cout << ans;

	return 0;
}


// S : 155
// U : 
// T : 
// C :
// Total :