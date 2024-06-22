#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(int cur, int& order, vector<bool>& isDummy, long long& num, int& check, int depth, int mxDepth)
{
    if (!check) return;

    if (depth + 1 <= mxDepth)
        dfs(cur * 2, order, isDummy, num, check, depth + 1, mxDepth);

    if (num & (1LL << (isDummy.size() - order++)))
        isDummy[cur] = false;

    if (depth + 1 <= mxDepth)
        dfs(cur * 2 + 1, order, isDummy, num, check, depth + 1, mxDepth);

    if (depth != mxDepth && isDummy[cur] && (!isDummy[cur * 2] || !isDummy[cur * 2 + 1]))
        check = 0;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (auto num : numbers)
    {
        int depth = 1;
        while (((1LL << ((1LL << depth) - 1))) - 1 < num)
            depth++;

        int check = 1;
        int order = 1;
        int nodeCnt = (1 << depth) - 1;
        vector<bool> isDummy(nodeCnt, true);
        dfs(1, order, isDummy, num, check, 1, depth);

        answer.push_back(check);
    }

    return answer;
}