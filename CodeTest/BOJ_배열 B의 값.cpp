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

// 꼭짓점은 한 번
// 모서리는 두 번
// 가운데는 네 번 더해진다.

// 1, 꼭짓점 max < 가운데 min일 경우 교환
// 2. 모서리 max < 가운데 min일 경우 교환
// 3. 꼭짓점 max < 모서리 min일 경우 교환
// 3 경우 중 가장 큰 값을 출력한다.
// -> 문제 잘 못 읽음 -> 행 또는 열 전체를 교환하는 것임.

// 바꾸는 경우의 수 -> 1000 * 999 / 2 * 2 = 대충 100만
// 바꾸고 비교하는 시간복잡도는 O(1)으로 해야할듯.
// 그러면 바꾸는 비용에 대한 테이블을 갱신해야 한다.
// but 생각해보니 첫 번째 행, 마지막 행을 가운데 행이랑 바꾸는 경우만 생각하면 된다.

int main()
{
	fastio;

	int r, c;
	cin >> r >> c;

	int ans = 0;

	vector<int> rw(r); // r행의 총합
	vector<int> cw(c); // c열의 총합
	for (int i = 0; i < r; ++i)
		for(int j =0; j < c; ++j)
		{
			int num;  cin >> num;

			if ((i == 0 || i == r - 1) && (j == 0 || j == c - 1))
			{
				ans += num;
				rw[i] += num;
				cw[j] += num;
			}
			else if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
			{
				ans += num * 2;
				rw[i] += num * 2;
				cw[j] += num * 2;
			}
			else
			{
				ans += num * 4;
				rw[i] += num  * 4;
				cw[j] += num * 4;
			}
		}


	int mx = -INF;
	for(auto it : {0, r-1}) // 행 2개
	{
		for(int i = 1; i < r - 1; ++i) // 나머지 행 
		{
			int tmp = ans - rw[i] / 2 + rw[it];
			mx = max(mx, tmp);
		}
	}

	for (auto it : { 0, c - 1 }) // 열 2개
	{
		for (int i = 1; i < c - 1; ++i) // 나머지 열
		{
			int tmp = ans - cw[i] / 2 + cw[it];
			mx = max(mx, tmp);
		}
	}
	

	cout << max(ans, mx);

	return 0;
}


// S : 3 30
// U : 4 28
// T : 
// C :
// Total :
