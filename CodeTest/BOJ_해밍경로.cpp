#include <iostream>
#include <ratio>
#include <string>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
using ui = unsigned int;
using umii = std::unordered_map<int, int>;

using namespace std;

// 단순히 모든 간선 생성 -> 10만 10만 불가능
// 트리를 만든다?
// 1차이 나는건 어떻게 구할거지?
// 맵으로 숫자들 저장 하고 1차이 나는 숫자들을 맵에서 Find 최대 30log10만 600?
// break 할게 아니라 그냥 한 번 계산 때리고 memo이용하는것...

void dfs(vector<int>& ans, vector<int>& tmpAns, ui cur, int target, map<ui, int>& mapNum, const int& k, int& minLength, vector<bool>& visited)
{
	if (minLength < ans.size())
		return;

	auto curFind = mapNum.find(cur);

	if(curFind->second == target)
	{
		if (minLength > tmpAns.size())
		{
			minLength = tmpAns.size();
			ans = tmpAns;
		}
		return;
	}

	for(int i = 0; i < k; ++i)
	{
		ui tmp = cur;
		ui cmp = 1 << i;
		if (tmp & cmp)
			tmp -= cmp;
		else
			tmp += cmp;

		auto findNum = mapNum.find(tmp);
		if(findNum != mapNum.end() && !visited[findNum->second])
		{
			tmpAns.push_back(findNum->second);
			visited[findNum->second] = true;
			dfs(ans, tmpAns, findNum->first, target, mapNum, k, minLength, visited);
			visited[findNum->second] = false;
			tmpAns.pop_back();
		}
	}
}

int main()
{
	fastio;

	int n, k;
	cin >> n >> k;

	ui first;
	bool bfirst = true;
	umii mapNum;
	for(int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;
		ui num = 0;
		num = stoi(s, nullptr, 2);
		mapNum.insert({ num, i});
		if (bfirst)
		{
			first = num;
			bfirst = false;
		}
	}

	int T;
	cin >> T;

	vector<bool> visited(n + 1, false);
	vector <int> memo(n + 1, -1);

	queue<ui> Q;
	Q.push(first);
	visited[1] = true;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		// log10만 -> 20
		auto findCur = mapNum.find(cur);

		//if (findCur->second == target)
		//	break;

		// 30
		for (int i = 0; i < k; ++i)
		{
			ui tmp = cur ^ (1 << i);

			auto findNum = mapNum.find(tmp);
			if (findNum != mapNum.end() && !visited[findNum->second])
			{
				visited[findNum->second] = true;
				Q.push(findNum->first);
				memo[findNum->second] = findCur->second;
			}
		}
	}

	while(T--)
	{
		int target;
		cin >> target;

		// vector<int> tmpAns{ 1 };

		if(memo[target] != -1)
		{
			vector<int> ans;
			int tmpTarget = target;
			while (tmpTarget != -1)
			{
				ans.push_back(tmpTarget);
				tmpTarget = memo[tmpTarget];
			}
			for(auto it = ans.rbegin(); it != ans.rend(); ++it)
			{
				cout << *it << " ";
			}
			cout << "\n";
		}
		else
			cout << -1 << "\n";


		//dfs(ans, tmpAns, first, target, mapNum, k, minLength, visited);
	}

	return 0;
}


// S : 8:42
// U : 8:46
// T : 9:04
// C : 10:30
// Total : 1h48m