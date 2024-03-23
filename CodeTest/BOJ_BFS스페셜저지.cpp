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

// 풀이시간이 가장 빠른 풀이
// bfsOrder기준으로 adjList를 정렬하고 BFS진행하며 2부터 N까지와 각 방문 정점들을 비교하는 방식
// 실전에서 쓰긴 어려울 듯. 직관적이지 않음.



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

	// input
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
	// end of input

	// 시작 인덱스가 1이 아닐경우 71퍼 예외 테케 
	if (bfsOrder[1] != 1)
	{
		cout << 0;
		return 0;
	}

	// adjList 미리 sort
	for(int i = 0; i < adjList.size(); ++i)
	{
		sort(adjList[i].begin(), adjList[i].end());
	}

	vector<bool> visited(v + 1, false);
	queue<int> Q;
	Q.push(1);
	visited[1] = true;

	// bfsOrder과 비교할 시작 인덱스 
	int cmpIdx = 2;

	bool check = true;

	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		// 비교할 방문이 안된 정점들
		vector<int> save;
		for(auto it : adjList[cur])
		{
			if (visited[it]) continue;
			visited[it] = true;
			save.push_back(it);
		}

		// N개 고정이라 상관 안써도 됨
		//if(cmpIdx + save.size() > v + 1)
		//{
		//	check = false;
		//	break;
		//}

		// 방문이 안된 정점 수 만큼 bfsOrder에서 빼옴
		vector<int> tmp(bfsOrder.begin() + cmpIdx, bfsOrder.begin()+ cmpIdx + save.size());

		// tmp 자리는 값으로 전달
		// tmp sort해서 각 인덱스 값 비교
		bool ret = cmp(tmp, save);
		if(ret == false)
		{
			check = false;
			break;
		}

		// 위에서 안 걸려졌다면 sort안된 tmp를 Q에 넣어줌.
		for(auto it : tmp)
		{
			Q.push(it);
		}

		// 비교할 시작 인덱스를 늘려줌.
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