#include <bits/stdc++.h>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

// ofstream 부분 지울 것!
// ltrim rtrim은 복사 ㄴㄴ

using pii = pair<int, int>;
// PQ?
int Moves(vector<int> arr) {
    // s 앞에서 홀수, d 뒤에서 짝수
    int s = 0;
    int d = arr.size() - 1;

    while (s < arr.size() && arr[s] % 2)
        ++s;

    while (d >= 0 && arr[d] % 2 == 0)
        --d;

    int ans = 0;
    while (s < d)
    {
        ++ans;
        ++s;
        while (s < arr.size() && arr[s] % 2)
            ++s;
        --d;
        while (d >= 0 && arr[d] % 2 == 0)
            --d;
    }

    return ans;
}

int main()
{
    Moves({ 5,
8,
5,
11,
4,
6 });
}



string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](int ch) { return !isspace(ch); })
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](int ch) { return !isspace(ch); }).base(),
        s.end()
    );

    return s;
}