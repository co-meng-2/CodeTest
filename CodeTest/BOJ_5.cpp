#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// 가장 작은 자릿수부터 5>= 인지 확인
// 1. 5>= 라면 5를 하나 확보
// 2, 5< 라면 윗 자릿수에 1을 더하고 5를 하나 확보
// 3. 1을 확보 다했다면 더 이상 비교하지 말고 앞 자릿수를 차곡차곡 더해줌

using LZ = long long;

LZ func(LZ n, LZ k)
{
	string a = to_string(n);
	if (k <= count(begin(a), end(a), '5')) return n;

	n /= 10;
	if (a.back() > '5')
	{
		a = to_string(++n);
		if (k <= count(begin(a), end(a), '5')) return n * 10;
	}
	return func(n, k - 1) * 10 + 5;
}

int main()
{
	LZ N, K;
	cin >> N >> K;
	cout << func(N + 1, K);
	return 0;
}


// S : 135
// U : 135
// T : 142
// C :
// Total :
