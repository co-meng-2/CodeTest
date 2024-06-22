#include <iostream>
#include <stack>
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

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

string str;
string explo;

// 터뜨리는데 순서가 상관 없다. -> 터뜨릴 수 있을 때마다 터뜨림.

int main()
{
	fastio;

	cin >> str;
	cin >> explo;

	string stk;
	for (int i = 0; i < str.size(); ++i)
	{
		stk.push_back(str[i]);
		if(str[i] == explo.back() && stk.size() >= explo.size())
			if (stk.find(explo, stk.size() - explo.size()) != string::npos)
				stk.erase(stk.size() - explo.size(), explo.size());
	}

	if (stk.empty())
		cout << "FRULA";
	else
		cout << stk;


	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :