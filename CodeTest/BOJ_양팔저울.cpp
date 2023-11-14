#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

bool dp[15001];

int main()
{
	fastio;

	int N, M;
	cin >> N;
	vector<int> vecWeight(N);
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> vecWeight[i];
		sum += vecWeight[i];
	}

	cin >> M;
	vector<int> vecM(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> vecM[i];
	}
	dp[0] = true;

	for (int i = 0; i < N; ++i)
	{
		vector<int> nextTrue;
		for (int j = 0; j <= sum; ++j)
		{
			if (dp[j])
			{ 
				nextTrue.push_back(j + vecWeight[i]);
				nextTrue.push_back(abs(j - vecWeight[i]));
			}
		}
		for (auto ntrue : nextTrue)
		{
			dp[ntrue] = true;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		if (vecM[i] <= 15000 && dp[vecM[i]]) cout << "Y ";
		else cout << "N ";
	}

	

	return 0;
}

// 추의 개수 N 30이하
// 추의 무게 500 이하
// 무게를 확인하고자 하는 추 M
// M무게 40000이하

// L R에 대해서 L = R이면 무게를 구분 할 수 있음
// 확인 추가 다른 추에 영향을 주지 않음.

// 추들의 자연수 합 차의 모든 경우의 수를 비교한다.
// 그렇다면 추를 오른쪽에 단다, 왼쪽에 단다, 쓰지 않는다. 3개의 경우의 수가 있고 이는 모든 경우를 탐색하는데 3^30을 뜻함

// S : 5:45
// U : 5:45
// T : 
// C :
// Total :