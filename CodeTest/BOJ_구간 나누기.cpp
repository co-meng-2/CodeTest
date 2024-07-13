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
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// M개의 구간으로 나누는 것은 M -1개를 빼면된다.
// 1. 가장 작은 숫자를 뺀다.
// 2. 구간이 M개 인지 확인.
// 2-1. 아니라면 1로
// 2-2. 맞다면 끝

// 

int n, m;
int nums[100];

int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> nums[i];



	return 0;
}


// S : 5 8
// U : 5 8
// T : 5 10
// C :
// Total :
