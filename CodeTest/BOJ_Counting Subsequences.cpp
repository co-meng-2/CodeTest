#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        ll cnt = 0;
        vector<int> nums(n);
        unordered_map<ll, vector<int>> um;
        unordered_map<ll, vector<int>>::iterator umfind;
        ll acc = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
            acc += nums[i];
            umfind = um.find(acc);
            if (umfind != um.end())
                umfind->second.push_back(i);
            else
                um.insert({ acc, {i} });
				
        }

        umfind = um.find(47);
        if(umfind != um.end())
			cnt += umfind->second.size();

        ll findNum = 47;
        for (int i = 1; i < n; ++i)
        {
            findNum += nums[i - 1];
            umfind = um.find(findNum);
            if(umfind != um.end())
            {
                vector<int>& idxs = um.find(findNum)->second;
                cnt += (idxs.end() - lower_bound(idxs.begin(), idxs.end(), i));
            }
            
        }

        cout << cnt << "\n";
    }

    return 0;
}