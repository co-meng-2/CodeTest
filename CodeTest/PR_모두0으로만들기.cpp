#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

long long solution(vector<int> a, vector<vector<int>> edges) {

	// dfs 한 번 해서 트리 구조 파악
	// 걍 bfs하자... 함수 만들기 귀찮

	vector<long long> w(a.begin(), a.end());
	int vcnt = w.size();
	vector<int> parents(vcnt, -1);

	// 인접리스트 갱신
	vector<vector<int>> adjList(vcnt);
	for (auto edge : edges)
	{
		int s = edge[0];
		int e = edge[1];
		adjList[s].push_back(e);
		adjList[e].push_back(s);
	}

	
	vector<int> leafs; // Q를 시작할 Leaf Nodes
	vector<int> childCnt(vcnt, 0); // 위상정렬 할 때 사용할 Child의 갯수
	vector<int> visited(vcnt, false);
	queue<int> Q;
	Q.push(0);
	visited[0] = true;
	// leaf Nodes찾고 부모 자식 관계 만드는 BFS
	while (!Q.empty())
	{
		auto front = Q.front();
		Q.pop();

		bool check = false;
		for (auto it : adjList[front])
		{
			if (visited[it]) continue;
			visited[it] = true;
			check = true;
			parents[it] = front;
			childCnt[front]++;
			Q.push(it);
		}

		if (check == false)
			leafs.push_back(front);
	}

	// leaf부터 시작해서 올라가며 cur의 parent에 자신의 값을 더해줌
	// 이때 자신이 가지고 있는 모든 자식들이 더해졌을 때만 Q에 Push
	long long ans = 0;
	for (auto leaf : leafs)
	{
		Q.push(leaf);
	}

	while (!Q.empty())
	{
		auto front = Q.front();
		Q.pop();
		if (front == 0) continue; // Root 예외처리

		int p = parents[front];
		// 제공되는 벡터 int라 long long만들어서 써줘야 됨.
		w[p] += w[front];
		ans += abs(w[front]);
		childCnt[p]--;

		if (childCnt[p] == 0)
			Q.push(p);
	}

	if (w[0] == 0)
		return ans;
	else
		return -1;
}