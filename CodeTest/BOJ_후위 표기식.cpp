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
#include <cctype>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

string str;
string ans;

int main()
{
	fastio;
	
	cin >> str;
	stack<char> stk;
	for(int i = 0; i < str.size(); ++i)
	{
		if (isalpha(str[i]))
			ans += str[i];
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!stk.empty() && stk.top() != '(')
			{
				ans += stk.top();
				stk.pop();
			}
			stk.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
			{
				ans += stk.top();
				stk.pop();
			}
			stk.push(str[i]);
		}
		else if (str[i] == '(')
			stk.push(str[i]);
		else if(str[i] == ')')
		{
			while(!stk.empty())
			{
				if (stk.top() == '(')
				{
					stk.pop();
					break;
				}
					
				ans += stk.top();
				stk.pop();

			}
		}
	}

	while (!stk.empty())
	{
		ans += stk.top();
		stk.pop();
	}

	cout << ans;

	return 0;
}



// S : 
// U : 
// T : 
// C :
// Total :