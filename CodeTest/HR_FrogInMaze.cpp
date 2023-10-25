#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

// obstacle exit mine
// surrounded by obstacle
// has tunnel

struct tPoint
{
    int row;
    int col;
};

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);


    char board[21][21]{};
    for (int n_itr = 1; n_itr <= n; n_itr++) {
        string row;
        getline(cin, row);

        // Write your code here
        for (int m_itr = 1; m_itr <= m; ++m_itr)
        {
            board[n_itr][m_itr] = row[m_itr - 1];
        }
    }

    map<string, tPoint> mapTunnel;
    for (int k_itr = 0; k_itr < k; k_itr++) {
        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int i1 = stoi(second_multiple_input[0]);

        int j1 = stoi(second_multiple_input[1]);

        int i2 = stoi(second_multiple_input[2]);

        int j2 = stoi(second_multiple_input[3]);

        // Write your code here
        board[i1][j1] = 'T';
        board[i2][j2] = 'T';

        mapTunnel.insert({ second_multiple_input[0] + 'r' + second_multiple_input[1] + 'c' , tPoint{i2, j2}});
        mapTunnel.insert({ second_multiple_input[2] + 'r' + second_multiple_input[3] + 'c', tPoint{i1, j1}});
    }

    // Write your code here

    return 0;
}
string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
