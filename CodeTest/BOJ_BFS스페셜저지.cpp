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
#include <set>
#include <string>

using namespace std;

// Q에 검증하며 넣으면 되지 않을까?

// 쓸 수 있는 정보



bool cmp(vector<int> l, vector<int>& r)
{
	sort(l.begin(), l.end());
	for(int i = 0; i < l.size(); ++i)
	{
		if (l[i] != r[i]) return false;
	}
	return true;
}

int main()
{
	fastio;

	int v;
	cin >> v;


	vector<vector<int>> adjList(v+1);
	for(int i = 1; i <= v-1; ++i)
	{
		int s, d;
		cin >> s >> d;
		adjList[s].push_back(d);
		adjList[d].push_back(s);
	}

	vector<int> bfsOrder(v+1);
	for(int i = 1; i <= v; ++i)
	{
		cin >> bfsOrder[i];
	}

	if (bfsOrder[1] != 1)
	{
		cout << 0;
		return 0;
	}

	for(int i = 0; i < adjList.size(); ++i)
	{
		sort(adjList[i].begin(), adjList[i].end());
	}

	vector<bool> visited(v + 1, false);
	queue<int> Q;
	Q.push(bfsOrder[1]);
	visited[bfsOrder[1]] = true;
	int cmpIdx = 2;

	bool check = true;

	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		vector<int> save;
		for(auto it : adjList[cur])
		{
			if (visited[it]) continue;
			visited[it] = true;
			save.push_back(it);
		}

		//if(cmpIdx + save.size() > v + 1)
		//{
		//	check = false;
		//	break;
		//}
		vector<int> tmp(bfsOrder.begin() + cmpIdx, bfsOrder.begin()+ cmpIdx + save.size());

		bool ret = cmp(tmp, save);
		if(ret == false)
		{
			check = false;
			break;
		}

		for(auto it : tmp)
		{
			Q.push(it);
		}
		
		cmpIdx += tmp.size();
	}

	if (check) cout << 1;
	else cout << 0;

	return 0;
}


// S : 612
// U : 612
// T : 617
// C : 730
// Total : 50min (alba)