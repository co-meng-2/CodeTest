	#include <string>
	#include <vector>
	#include <algorithm>
	#include <iostream>

	using namespace std;
	using ll = long long;


	long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
	    long long answer = 0;

	    // y,x 로부터 역계산?
	    // 되는 범위로 생각을하자

	    // n행 m열
	    // x행 y열

	    ll ys = x;
	    ll ye = x + 1;
	    ll xs = y;
	    ll xe = y + 1;

	    bool check = true;
	    for (auto it = queries.rbegin(); it != queries.rend(); ++it)
	    {
	        int com = it->at(0);
	        ll dx = it->at(1);

	        if(com == 0) // -x
	        {
		        if(xs == 0)
		        {
	                xe = min(xe + dx, (ll)m);
		        }
	            else
	            {
	                xs += dx;
	                if(xs > m - 1)
	                {
	                    check = false;
	                    break;
	                }
	                xe += dx;
	                xe = min(xe, (ll)m);
	            }
	        }
	        else if(com == 1) // +x
	        {
		        if(xe == m)
		        {
	                xs = max(xs - dx, 0LL);
		        }
	            else
	            {
	                xs -= dx;
	                xs = max(xs, 0LL);
	                xe -= dx;
	                if(xe < 1)
	                {
	                    check = false;
	                    break;
	                }
	            }
	        }
	        else if(com == 2) //-y
	        {
	            if (ys == 0)
	            {
	                ye = min(ye + dx, ll(n));
	            }
	            else
	            {
	                ys += dx;
	                if(ys > n - 1)
	                {
	                    check = false;
	                    break;
	                }
	                ye += dx;
	                ye = min(ye, (ll)n);
	            }
	        }
	        else if(com == 3) // +y
	        {
	            if (ye == n)
	            {
	                ys = max(ys - dx, 0LL);
	            }
	            else
	            {
	                ys -= dx;
	                ys = max(ys, 0LL);
	                ye -= dx;
	                if(ye < 1)
	                {
	                    check = false;
	                    break;
	                }
	            }
	        }
	    }

	    if(check)
			answer = (ye - ys) * (xe - xs);

	    return answer;
	}

	int main()
	{
	    int n, m, x, y, k;
	    cin >> n >> m >> x >> y >> k;

	    vector<vector<int>> queries(k);
	    for(int i = 0; i < k; ++i)
	    {
	        int com, dx;
	        cin >> com >> dx;
	        queries[i].push_back(com);
	        queries[i].push_back(dx);
	    }
	        
		cout <<  solution(n, m, x, y, queries);

	    return 0;
	}