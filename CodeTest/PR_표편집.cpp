#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    for (int i = 0; i < n; ++i)
        answer.push_back('O');

    stack<int> del;
    priority_queue<int> cur;
    priority_queue<int, vector<int>, greater<>> nxt;

    for (int i = 0; i < n; ++i)
    {
        if (i <= k)
            cur.push(i);
        else
            nxt.push(i);
    }

    // n개 중에 k idx가 현재
    for (const auto& str : cmd)
    {
        auto front = str.front();
        if (front == 'U')
        {
            int move = stoi(str.substr(2));
            for (int i = 0; i < move; ++i)
            {
                nxt.push(cur.top());
                cur.pop();
            }
        }
        else if (front == 'D')
        {
            int move = stoi(str.substr(2));
            for (int i = 0; i < move; ++i)
            {
                cur.push(nxt.top());
                nxt.pop();
            }
        }
        else if (front == 'C')
        {
            del.push(cur.top());
            cur.pop();
            if (!nxt.empty())
            {
                cur.push(nxt.top());
                nxt.pop();
            }
        }
        else if (front == 'Z')
        {
            auto top = del.top();
            del.pop();
            if (top > cur.top())
                nxt.push(top);
            else
                cur.push(top);
        }
    }

    while (!del.empty())
    {
        answer[del.top()] = 'X';
        del.pop();
    }

    return answer;
}                                                                                                                                                                                   