#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#include "MyDebug.h"

using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

struct tNode
{
    //tNode* p;
    tNode* l;
    tNode* r;
    int idx;
    int y;
    int x;

    bool operator<(const tNode& rhs) const
    {
        return y > rhs.y;
    }
};

void dfs(tNode* cur, vector<vector<int>>& answer, vector<tNode>& nodes)
{
    if (cur == nullptr)
        return;

    answer[0].push_back(cur->idx);
    dfs(cur->l, answer, nodes);
    dfs(cur->r, answer, nodes);
    answer[1].push_back(cur->idx);
}

void test2(tNode* cur, vector<vector<int>>& answer, vector<tNode>& nodes)
{
    stack<tNode*> st;
    st.push(cur);
    while (!st.empty())
    {
        auto top = st.top();
        st.pop();

        answer[0].push_back(top->idx);
        if (top->r)
            st.push(top->r);
        if (top->l)
            st.push(top->l);
    }
}

vector<vector<int>> solution(vector<vector<int>>& nodes) {
    vector<vector<int>> answer(2);

    vector<tNode> tNodes(nodes.size());
    for(int i = 0 ;i < nodes.size(); ++i)
    {
        tNodes[i].idx = i + 1;
        tNodes[i].l = nullptr;
        tNodes[i].r = nullptr;
        //tNodes[i].p = nullptr;
        tNodes[i].x = nodes[i][0];
        tNodes[i].y = nodes[i][1];
    }

    sort(tNodes.begin(), tNodes.end());
    for (int i = 1; i < tNodes.size(); ++i)
    {
        auto [l, r, idx, y, x] = tNodes[i];
        auto cur = &tNodes[0];
        while(true)
        {
            if (cur->x > x)
            {
                if (cur->l == nullptr)
                {
                    cur->l = &tNodes[i];
                    break;
                }
                else
                {
                    cur = cur->l;
                }
            }
            else
            {
                if (cur->r == nullptr)
                {
                    cur->r = &tNodes[i];
                    break;
                }
                else
                {
                    cur = cur->r;
                }
            }
        }
    }

    test2(&tNodes[0], answer, tNodes);

    return answer;
}

struct cmp {
    bool operator() (const tiii& l, const tiii& r) const {
        return std::get<0>(l) < std::get<0>(r);
    }
};

void dfs1(int cur, vector<vector<int>>& answer, vector<pii>& tree)
{
    if (cur == -1) return;

    answer[0].push_back(cur);
    dfs1(tree[cur].first, answer, tree);
    dfs1(tree[cur].second, answer, tree);
    answer[1].push_back(cur);
}

void test1(int cur, vector<vector<int>>& answer, vector<pii>& tree)
{
    stack<int> st;
    st.push(cur);
    while(!st.empty())
    {
        auto top = st.top();
        st.pop();

        answer[0].push_back(top);
        if (tree[top].second != -1)
    		st.push(tree[top].second);
        if (tree[top].first != -1)
			st.push(tree[top].first);
    }
}

vector<vector<int>> solution1(vector<vector<int>>& nodes) {
    vector<vector<int>> answer(2);

    for(int i = 0; i < nodes.size(); ++i)
    {
        nodes[i].push_back(i + 1);
    }

    sort(nodes.begin(), nodes.end(), [](vector<int>& l, vector<int>& r) -> bool
        {
            return l[1] > r[1];
        });

    const int INF = 1e9;    

    set<tiii, cmp> set;
    set.insert({ nodes[0][0], nodes[0][1], nodes[0][2] });
    set.insert({ -INF, INF, -1 });
    set.insert({ INF, INF, -1 });

    vector<pii> tree(nodes.size() + 1, {-1,-1});

    for(int i = 1; i < nodes.size(); ++i)
    {
        auto lb = set.lower_bound(tiii{ nodes[i][0], -1, -1});
        auto lbm = lb;
        lbm--;
        auto [lbx, lby, lbi] = *lb;
        auto [lbmx, lbmy, lbmi] = *lbm;

        if (lbmy > lby)
            tree[lbi].first = nodes[i][2];
        else
            tree[lbmi].second = nodes[i][2];
        set.insert({nodes[i][0], nodes[i][1], nodes[i][2]});
    }

    test1(nodes[0][2], answer, tree);

    return answer;
}

int main()
{
    vector<vector<int>> k2 = { {1,2,1,2},{3,3,4,4}, {5,5,6,0}, {6,0,0,0} };
    // 시드값을 얻기 위한 random_device 생성.
    std::random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    std::mt19937 gen(rd());

    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    int k = 100000;
	DIS(1, k);

    vector<vector<int>> input;
    input.reserve(k);
    vector<int> ycnt(k+1, 0);
    vector<int> xcnt(k+1 ,0);

    //for (int i = 0; i < k; ++i)
    //{
    //    input.push_back({ i + 1, i + 1 });
    //}

    for(int i = 0; i <k; ++i)
    {
        int x;
        int y;

        while (true)
        {
            x = dis(gen);
            if (xcnt[x] == 0)
            {
                xcnt[x]++;
                break;
            }
        }

        while (true)
        {
            y = dis(gen);
            if (ycnt[y] < 2)
            {
                ycnt[y]++;
                break;
            }
        }
        input.push_back({ x,y });
    }

    D_CURTIME;
	solution1(input);
    D_ELAPSETIME;


    D_CURTIME;
	solution(input);
    D_ELAPSETIME;
}

// solution -> O(max_level * n)
// solution -> O(nlogn)