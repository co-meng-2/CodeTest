#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 어디서나 와이파이 -> 공유기 C개
// 한 집에는 공유기 하나를 설치 가능
// 가장 인접한 두 공유기 사이의 거리 가능한 크게

// 문제
// 집의 갯수 N  2 - 200,000
// 공유기의 갯수 C 2 - N
// 집의 좌표 xi 0 - 10억
// 가장 인접한 두 공유기 사이의 최대 거리

// 풀이
// 2개면 양 끝
// 3개면 양 끝의 중간
// 4개면 복잡해짐

// 간격을 hi lo로 정한다?
// check의 조건 최대 간격 MaxK로 놓기 가능?

int N, C;
int arr[200001]{};

bool check(int interval)
{
	int idx = 1;
	for(int i = 0; i < C; ++i)
	{
		int acc = 0;
		while(true)
		{
			idx++;
			if (idx > N)
				return false;
			acc += arr[idx] - arr[idx - 1];
			if (acc >= interval) break;
		}
	}
	return true;
}

int main()
{
	fastio;
	cin >> N >> C;

	for(int i = 1; i <= N; ++i)
		cin >> arr[i];

	std::sort(arr + 1, arr + N + 1);

	// 가장 앞에 배치되어 있다고 생각
	C -= 1;

	int lo = 1;
	int hi = 1'000'000'001;

	while(lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid) == check(lo)) // true
			lo = mid;
		else
			hi = mid;
	}

	cout << lo;

	return 0;
}

