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

int n;
string s;
vector<int> nums;
vector<char> opers;
vector<int> calc;
int mx = numeric_limits<int>::min();

void dfs(int cur, int sum)
{
	if(cur == opers.size())
	{
		mx = max(mx, sum);
		return;
	}

	int NxtSum = sum;
	if (opers[cur] == '*')
		NxtSum *= nums[cur];
	else if (opers[cur] == '+')
		NxtSum += nums[cur];
	else if (opers[cur] == '-')
		NxtSum -= nums[cur];
	dfs(cur + 1, NxtSum);

	if (cur <= (int)opers.size() - 2) return;

	int operVal = 0;
	if (opers[cur + 1] == '*')
		operVal = nums[cur] * nums[cur + 1];
	else if (opers[cur + 1] == '+')
		operVal = nums[cur] + nums[cur + 1];
	else if (opers[cur + 1] == '-')
		operVal = nums[cur] - nums[cur + 1];

	NxtSum = sum;
	if (opers[cur] == '*')
		NxtSum *= operVal;
	else if (opers[cur] == '+')
		NxtSum += operVal;
	else if (opers[cur] == '-')
		NxtSum -= operVal;

	dfs(cur + 2, NxtSum);
}

int main()
{
	fastio;
	cin >> n;
	cin >> s;

	for(int i = 0; i < s.size(); i+=2)
		nums.push_back(s[i] - '0');

	opers.push_back('+');
	for (int i = 1; i < s.size(); i+=2)
		opers.push_back(s[i]);
	dfs(0, 0);

	cout << mx;

	return 0;
}


// S : 12 07
// U : 12 08
// T : 
// C :
// Total :
