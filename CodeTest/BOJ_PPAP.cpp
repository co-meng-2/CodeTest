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

// PPAP로 바꾼 문자열 사이에 순서가 있나?

// PPAP
// PPAPPAP
// PPPAPAP
// PPAPPAP
// PPAPPAP
// 순서가 상관 없는듯

int main()
{
	fastio;

	string str;
	cin >> str;
	string stk;
	for(auto c : str)
	{
		stk += c;
		
		while ( stk.size() >= 4 && stk[stk.size() - 1] == 'P' && stk[stk.size() - 2] == 'A' && stk[stk.size() - 3] == 'P' && stk[stk.size() - 4] == 'P')
		{
			stk.erase(stk.size() - 4, 4);
			stk += 'P';
		}
	}

	if (stk.size() == 1 && stk.front() == 'P')
		cout << "PPAP";
	else
		cout << "NP";


	return 0;
}


// S : 432
// U : 432
// T : 436
// C : 443
// Total : 11min
