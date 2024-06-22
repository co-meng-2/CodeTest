#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int ToSecond(string& str)
{
    int sec = 0;
    sec += stoi(str.substr(0, 2)) * 3600;
    sec += stoi(str.substr(3, 2)) * 60;
    sec += stoi(str.substr(6, 2));
    return sec;
}

pii LogToSecond(string& str)
{
    pii sec{};
    sec.first += stoi(str.substr(0, 2)) * 3600;
    sec.first += stoi(str.substr(3, 2)) * 60;
    sec.first += stoi(str.substr(6, 2));

    sec.second += stoi(str.substr(9, 2)) * 3600;
    sec.second += stoi(str.substr(12, 2)) * 60;
    sec.second += stoi(str.substr(15, 2));

    return sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int pt = ToSecond(play_time);
    int at = ToSecond(adv_time);

    vector<int> acc(pt + 2, 0);
    for (auto& log : logs)
    {
        pii lt = LogToSecond(log);
        acc[lt.first] += 1;
        acc[lt.second + 1] += -1;
    }

    for (int i = 1; i < acc.size(); ++i)
    {
        acc[i] += acc[i - 1];
    }

    for (int i = 1; i < acc.size(); ++i)
    {
        acc[i] += acc[i - 1];
    }

    int mx = -1;
    for (int i = 0; i <= pt - at; ++i)
    {
        int s = i - 1;
        int e = i + at;
        mx = max(mx, s == -1 ? acc[e] : acc[e] - acc[s]);
    }

    answer = to_string(mx);
    return answer;
}

int main()
{
    solution("99:59:59", "25:00:00", { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" });
    return 0;
}