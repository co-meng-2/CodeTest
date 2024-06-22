#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

// dlru
string solution(int n, int m, int sy, int sx, int ey, int ex, int k) {
    string answer = "";

    int lenPath = abs(sy - ey) + abs(sx - ex);
    int remain = k - lenPath;

    if (remain < 0 || remain % 2)
        return "impossible";
    int cy = sy;
    int cx = sx;

    int cnt = 0;
    while (true)
    {
        // d l r u
        if (cy < n && cnt + abs(cy + 1 - ey) + abs(cx - ex) <= k)
        {
            cy++;
            answer += 'd';
        }
        else if (cx > 1 && cnt + abs(cy - ey) + abs(cx - 1 - ex) <= k)
        {
            cx--;
            answer += 'l';
        }
        else if (cx < m && cnt + abs(cy - ey) + abs(cx + 1 - ex) <= k)
        {
            cx++;
            answer += 'r';
        }
        else if (cy > 1 && cnt + abs(cy - 1 - ey) + abs(cx - ex) <= k)
        {
            cy--;
            answer += 'u';
        }
        else
        {
            break;
        }

        cnt++;
    }


    return answer;
}