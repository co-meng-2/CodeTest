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
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

struct tNode
{
	int rc = -1;
	int lc = -1;
};

int n;
vector<int> in;
vector<int> inIdxs;
vector<int> post;
vector<tNode> tree;

void dfs(int& postIdx, int s, int e)
{
	if (postIdx == 0) return;

	int curRootNum = post[postIdx];
	int inIdx = inIdxs[curRootNum];

	if(inIdx < e)
	{
		tree[curRootNum].rc = post[--postIdx];
		dfs(postIdx, inIdx + 1, e);
	}

	if(inIdx > s)
	{
		tree[curRootNum].lc = post[--postIdx];
		dfs(postIdx, s, inIdx - 1);
	}
}

void ans(int cur)
{
	cout << cur+ 1 << " ";
	if(tree[cur].lc >= 0)
		ans(tree[cur].lc);
	if (tree[cur].rc >= 0)
		ans(tree[cur].rc);
}

int main()
{
	fastio;

	cin >> n;
	in.resize(n);
	inIdxs.resize(n);
	post.resize(n);
	tree.resize(n);

	int num;	

	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		in[i] = num - 1;
		inIdxs[in[i]] = i;
	}
		
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		post[i] = num - 1;
	}

	int postIdx = n - 1;
	dfs(postIdx, 0, n - 1);

	int root = post[n - 1];
	ans(root);
	

	return 0;
}


// S : 500
// U : 
// T : 
// C :
// Total :