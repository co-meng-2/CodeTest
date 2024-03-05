#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// A B 피자
// A로 만들 수 있는 합 B로 만들 수 있는 합
// dp[n] = dpA[n-k] * dpB[k] 들의 합
// 그러면 각 피자로 만들 수 있는 합은? 중복 계산해야되는데..
// A[n] = A[n-k] * A[k]의 합

// tlqkf 연속된 피자합이네 
// 누적합 1000 * 1000 백만 안에 갱신 가능
// 



int main()
{
	fastio;

	int Size;
	cin >> Size;

	int ADiv, BDiv;
	cin >> ADiv >> BDiv;


	vector<int> pizzaA(ADiv + 1, 0);
	vector<int> pizzaB(BDiv + 1, 0);

	int allsumA = 0;
	for(int i = 1; i <= ADiv; ++i)
	{
		int input;
		cin >> input;
		pizzaA[i] = input;
		allsumA += input;
	}

	int allsumB = 0;
	for (int i = 1; i <= BDiv; ++i)
	{
		int input;
		cin >> input;
		pizzaB[i] = input;
		allsumB += input;
	}

	vector<int> memoA(2'000'001, 0);
	for(int i = 1; i <= ADiv; ++i)
	{
		int sum = 0;
		for( int j = 0; j <= ADiv - 2; ++j )
		{
			int nxtIdx = i + j;
			if (nxtIdx > ADiv)
				nxtIdx -= ADiv;
			sum += pizzaA[nxtIdx];
			if (sum > Size) 
				break;
			memoA[sum]++;
		}
	}
	memoA[allsumA]++;
	memoA[0] = 1;


	vector<int> memoB(2'000'001, 0);
	for (int i = 1; i <= BDiv; ++i)
	{
		int sum = 0;
		for (int j = 0; j <= BDiv - 2; ++j)
		{
			int nxtIdx = i + j;
			if (nxtIdx > BDiv) 
				nxtIdx -= BDiv;
			sum += pizzaB[nxtIdx];
			if (sum > Size)
				break;
			memoB[sum]++;
		}
	}
	memoB[allsumB]++;
	memoB[0] = 1;

	int output = 0;
	for (int i = 0; i <= Size; ++i)
	{
		output += memoA[i] * memoB[Size - i];
	}
	cout << output;


	return 0;
}

// S : 12:29
// U : 12:30
// T : 12:33 문제 잘못 봄 1:05
// C :  1:25
// Total : 56min