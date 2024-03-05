#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <string>
using std::string;

// dfs backtracking?
// greedy
// B, C가 가장 앞인 경우가 이상적
// 우선 순위 C -> B -> A
// BBCBACB때문에 안됨.
// BCBA"BCB
// 균등하게 배치한다?
// C..C..C..C
// CCCCBBBBBAAA로 반례가 또 있네ㅋㅋㅋ
// CBACBACBABCB

// 이러면 DP인데?ㅋㅋㅋ


void dfs(int maxDepth, int depth, vector<int>& cnt, string& cur, string& mapping, string& ans, bool& bFind)
{
	if(depth == maxDepth && bFind == false)
	{
		bFind = true;
		ans = cur;
	}

	for(int i = 2; i >=0; --i)
	{
		if(cnt[i] != 0)
		{
			bool bPossible = true;
			for(int j = i -1 ; j >= 0; --j)
			{
				if ((int)cur.size() - 1 - j < 0) 
					continue;
				if(cur[cur.size() -1 -j] == mapping[i])
				{
					bPossible = false;
				}
			}

			if (bPossible)
			{
				cnt[i]--;
				cur.push_back(mapping[i]);
				dfs(maxDepth, depth + 1, cnt, cur, mapping, ans, bFind);
				cur.pop_back();
				cnt[i]++;
			}
		}
	}
}

int check(string& str, vector<int>& cnt, string& order, int length)
{
	if (cnt[1] > 0 && cnt[1] > (length - str.length()) / 2 && str.back() != 'B')
		return 1;

	for(int i = 2; i >=0; --i)
	{
		if (cnt[i] == 0) continue;
		bool bPossible = true;

		for(int j = 0; j < i; ++j)
		{
			int prevIndex = (int)str.length() - 1 - j;
			if (prevIndex < 0) continue;
			if (str[prevIndex] == order[i])
			{
				bPossible = false;
				break;
			}
		}
		if (bPossible) return i;
	}
	return -1;
}

bool dp[51][51][51][3][3] = { false, };
vector<int> cnt(3, 0);
string ans = "";
string cur = "";


void dfs(int a, int b, int c, int pp, int p)
{
	if (a == cnt[0] && b == cnt[1] && c == cnt[2])
	{
		ans = cur;
		return;
	}

	if (dp[a][b][c][pp][p]) return;
	dp[a][b][c][pp][p] = true;

	if(a < cnt[0])
	{
		cur.push_back('A');
		dfs(a + 1, b, c, p, 0);
		cur.pop_back();
	}
	if (b < cnt[1] && p != 1)
	{
		cur.push_back('B');
		dfs(a , b+1, c, p, 1);
		cur.pop_back();
	}
	if (c < cnt[2] && pp != 2 && p != 2)
	{
		cur.push_back('C');
		dfs(a, b, c+1, p, 2);
		cur.pop_back();
	}
}

int main()
{
	fastio;

	string str;
	cin >> str;
	

	for(auto c : str)
	{
		if (c == 'A')
			cnt[0]++;
		else if (c == 'B')
			cnt[1]++;
		else if (c=='C')
			cnt[2]++;
	}

	//// dp dfs
	//dfs(0, 0, 0, 0, 0);

	//if (ans.empty())
	//	cout << -1;
	//else
	//	cout << ans;


	// greedy
	string order = "ABC";
	string ans = "";

	for (int i = 2; i >= 0; i--)
	{
		string tmpAns = "";
		vector<int> tmpCnt = cnt;
		if (tmpCnt[i])
		{
			tmpAns.push_back(order[i]);
			tmpCnt[i]--;
			while (tmpAns.size() < str.size())
			{
				int possibleCharIdx = check(tmpAns, tmpCnt, order, str.length());
				if (possibleCharIdx == -1) break;
				tmpAns.push_back(order[possibleCharIdx]);
				tmpCnt[possibleCharIdx]--;
			}
		}
		if (tmpAns.size() == str.size())
		{
			ans = tmpAns;
			break;
		}
	}

	if (ans.size() != str.size())
		cout << -1;
	else
		cout << ans;


	// dfs backtracking
	/*string mapping = "ABC";
	string cur = "";
	
	string ans = "";
	bool bFind = false;
	dfs(str.size(), 0, cnt, cur, mapping, ans, bFind);

	if (ans.size() == 0)
		cout << -1;
	else
		cout << ans;*/
	return 0;
}


// S : 10:21
// U : 10:22
// T : 10:26 DFS 11:04 greedy
// C : 10:51 DFS
// Total :