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
#include <unordered_set>
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// L 길이	
// K 자를 수 있는 위치의 갯수 -> 1 ~ L
// C 자를 수 있는 횟수

// KlogL 이면 30만 정도

int L, K, C;
vector<int> locs;

// 처음 자른 통나무 찾기 + 가장 긴 통나무의 최솟값 찾기
bool check(int mid, int cnt = 0, int s = 0 ,int sIdx = 0)
{
	int tmp = s;
	if (cnt < C)
	{
		for (int i = sIdx; i < locs.size(); ++i)
		{
			if (locs[i] - s <= mid)  // 일단 보류
			{
				tmp = locs[i];
			}
			else // 확정
			{
				s = tmp;
				cnt++;
				if (cnt == C)
				{
					if (L - s <= mid)
						return true;
					return false;
				}

				if (locs[i] - s <= mid)  // 일단 보류
				{
					tmp = locs[i];
				}
			}
		}
	}

	s = tmp;
	if (L - s <= mid)
		return true;
	return false;
}

int main()
{
	fastio;
	cin >> L >> K >> C;
	locs.resize(K);
	for (int i = 0; i < K; ++i)
		cin >> locs[i];

	sort(locs.begin(), locs.end());

	int lo = 1;
	int hi = 1e9;

	while(lo <= hi)
	{
		int mid = (lo + hi) / 2;

		if (check(mid))
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	// 어떻게 가장 처음 자른 통나무를 구할 것인가.
	int sIdx = -1;
	for(int i  = 0; i < locs.size(); ++i)
	{ 
		int s = locs[i];
		if(check(lo, 1, s, i + 1))
		{
			sIdx = i;
			break;
		}
	}

	cout << lo << " " << locs[sIdx];

	return 0;
}


// S : 3 58
// U : 3 59
// T : 4 05
// C : 5 30
// Total : 1h 27min

// Comment
// 처음 Check을 만들었던 것을 처음 자른 통나무를 구하기 위한 형태로 개조하면서, cnt가 1개로 시작하는 경우가 생겼다.
// 이에 대한 반례를 생각하지 못해 시간이 오래 걸렸다.
