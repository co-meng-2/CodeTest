#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
#include <vector>
#include <cmath>

#include <climits>

using namespace std;

void dfs(int dep, int maxDep, int& visitOrder, vector<int>& vec, const long long& num, int treeOrder = 1)
{
    if (dep < maxDep)
        dfs(dep + 1, maxDep, visitOrder, vec, num, treeOrder * 2);

    int bitCnt = pow(2, maxDep) - 1;
    int bitPos = bitCnt - visitOrder;
    if (num & (1LL << bitPos - 1))
        vec[treeOrder - 1] = 1;
     
    visitOrder++;

    if (dep < maxDep)
        dfs(dep + 1, maxDep, visitOrder, vec, num, treeOrder * 2 + 1);
}

void dfs2(int idx, vector<int>& vec, vector<bool>& vecVisited)
{
    vecVisited[idx] = true;
    int L = (idx + 1) * 2;
	if(L - 1 < vec.size() && vec[L - 1])
        dfs2(L-1, vec, vecVisited);

    int R = (idx + 1) * 2 + 1;
    if (R- 1 < vec.size() && vec[R - 1])
        dfs2(R-1, vec, vecVisited);
}

vector<int> solution(vector<long long> numbers) {

    vector<int> answer;

    for(auto it : numbers)
    {
        int lo = 0;
        int hi = 6;

        // maxDepth Ã£±â
        while(lo +1 < hi)
        {
            int mid = (lo + hi) / 2;
            int nodeCnt = pow(2, mid) - 1;
            long long maxNum = pow(2, nodeCnt) - 1;
            if (maxNum >= it)
                hi = mid;
            else
                lo = mid;
        }

        vector<int> vec;
        vector<bool> vecVisited;
        vec.resize(pow(2, hi) - 1, 0);
        vecVisited.resize(pow(2, hi) - 1, false);
        int visitOrder = 0;
        dfs(1, hi, visitOrder, vec, it);

        int cnt = 0;
        if (vec[0])
        {
            for (int i = 0; i < vec.size(); ++i)
            {
                if (vec[i])
                {
                    if (vecVisited[i]) continue;
                    cnt++;
                    if (cnt == 2)
                        break;

                    dfs2(i, vec, vecVisited);
                }
            }
        }
        else
            cnt = 2;

        if (cnt < 2)
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}

int main()
{
	fastio;

    vector<int> test;
	vector<long long> input(1);
    while (true)
    {
        for (auto it : test)
            cout << it << "\n";
    }

	return 0;
}