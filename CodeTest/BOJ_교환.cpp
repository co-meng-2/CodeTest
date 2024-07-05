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

// 7C2 -> 21
// 최대 숫자 갯수 대충 100만
// 100만 * 21 * 10 = 2억1000만 할만한듯?

int mx = -1;
int n, k;

int main()
{
	fastio;

	cin >> n >> k;
	// 숫자중 조건에 맞춰 2개를 선택
	// 둘이 자리를 바꾼 수 um에 바꾼 cnt와 함꼐 넣음
	// cnt가 k라면 그 숫자 중 max를 기억
	// max를 출력

	int nsz = 0;
	int tmp = n;
	while(tmp)
	{
		tmp /= 10;
		nsz++;
	}

	
	queue<int> Q;
	Q.push(n);
	int cnt = 0;
	while(!Q.empty())
	{
		int qsz = Q.size();
		unordered_set<int> us;
		cnt++;
		while(qsz--)
		{
			auto cur = Q.front();
			Q.pop();

			for(int i = 0; i < nsz; ++i)
				for(int j = i + 1; j < nsz; ++j)
				{
					int iNum = (cur / (int)pow(10, i)) % 10;
					int jNum = (cur / (int)pow(10, j)) % 10;
					if ( j == nsz - 1 && iNum == 0) continue;

					int nxt = cur - iNum * pow(10, i) + iNum * pow(10, j) - jNum * pow(10, j) + jNum * pow(10, i);

					if (us.count(nxt)) continue;

					if (cnt == k)
						mx = max(mx, nxt);
					else
					{
						us.insert(nxt);
						Q.push(nxt);
					}
				}
		}
	}

	cout << mx;

	return 0;
}


// S : 10 47
// U : 10 48
// T : 10 54
// C :
// Total :
