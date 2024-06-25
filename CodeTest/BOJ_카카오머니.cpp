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

// 차액일때만 생각
// bn < a(n+1) 일 때, bn + M + a(n+1) = b(n+1) 이므로 M = b(n+1) - bn - a(n+1)이다.
// M 앞에 상수가 붙어있지만 이 상수는 무시하고 b(n+1), M을 기록한다.
// M끼리 GCD를 해서 가능한 최대 M을 구한다.
// b(n+1)의 최댓값이 최대 M보다 크거나 같은 것이 있다면 유효하지 않다. 

ll GCD(ll a, ll b)
{
	// prevM -1인 경우 처리
	if (a < 0)
		return b;
	ll ret = a % b;
	if (ret == 0)
		return b;
	else
		return GCD(b, ret);
}

int main()
{
	fastio;

	int n;
	cin >> n;

	ll prevD = 0;
	ll prevM = -1;
	ll mx = 0;

	for(int i = 0; i < n; ++i)
	{
		ll nxtS, nxtD, nxtM;
		cin >> nxtS >> nxtD;

		if( prevD + nxtS < 0 )
		{
			nxtM = nxtD - prevD - nxtS;
			prevM = GCD(prevM, nxtM);
			mx = max(mx, nxtD);
		}
		// 이 부분 때문에 오래 해맸는데, 문제의 요지가 이게 아닐텐데 왜 이런 테케를 넣어놨지;;;
		else if(prevD + nxtS != nxtD) // 양수 일 때, 더해진 금액이 맞는지 확인
		{
			cout << -1;
			return 0;
		}

		prevD = nxtD;
	}

	// 입금만 진행된 경우 아무숫자
	if (prevM == -1)
		cout << 1;
	// 잔액의 최댓값이 최대충전금액보다 작은 경우 유효하다
	else if (prevM > mx)
		cout << prevM;
	else
		cout << -1;


	return 0;
}


// S : 2 53
// U : 2 54
// T : 3 05
// C : 3 30
// Total :
