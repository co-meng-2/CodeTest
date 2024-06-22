#include <string>
#include <vector>

using namespace std;

int m;
bool GiSafe(vector<vector<bool>>& board0, vector<vector<bool>>& board1, int y, int x)
{
    if (y == 0 || board0[y - 1][x] || (x >= 1 && board1[y][x - 1]) || board1[y][x])
    {
        return true;
    }
    return false;
}

bool BoSafe(vector<vector<bool>>& board0, vector<vector<bool>>& board1, int y, int x)
{
    if ( (y -1 >= 0 && board0[y - 1][x]) || (y-1 >= 0 && x+1 <= m && board0[y - 1][x + 1]) || (x >= 1 && x + 1 <= m && board1[y][x - 1] && board1[y][x + 1]))
    {
        return true;
    }
    return false;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    m = n + 1;
    // frame[2] = 0기둥, 1보
    // frame[3] = 0삭제, 1설치
    // 보는 오른쪽으로 설치 [x, x+1}

    vector<vector<bool>> board0(n+1, vector<bool>(n+1, false));
    vector<vector<bool>> board1(n+1, vector<bool>(n+1, false));
    
    for (auto& frame : build_frame)
    {
        int cx = frame[0];
        int cy = frame[1];
        int type = frame[2]; // 0 기둥  1 보
        int action = frame[3]; // 0 삭제 1 건설

        if (action == 0)
        {
            if (type == 0)
            {
                board0[cy][cx] = false;
                // 위 기둥 
                if ( cy + 1 <= n && board0[cy + 1][cx])
                {
                    if(!GiSafe(board0, board1, cy+1, cx))
                    {
                        board0[cy][cx] = true;
                        continue;
                    }
                }

                // 위 우 보
                if (cy + 1 <= n && board1[cy + 1][cx])
                {
                    if (!BoSafe(board0, board1, cy + 1, cx))
                    {
                        board0[cy][cx] = true;
                        continue;
					}
				}
                // 위 왼 보
				if (cx - 1 >= 0 && cy + 1 <= n && board1[cy + 1][cx - 1])
                {
                    if (!BoSafe(board0, board1, cy + 1, cx - 1))
                    {
                        board0[cy][cx] = true;
                        continue;
                    }
                }
            }
            else
            {
                board1[cy][cx] = false;
                if (board0[cy][cx])
                {
	                if(!GiSafe(board0, board1, cy, cx))
	                {
                        board1[cy][cx] = true;
                        continue;
	                }
                }

                if (cx + 1 <= n && board0[cy][cx + 1])
                {
                    if (!GiSafe(board0, board1, cy, cx + 1))
                    {
                        board1[cy][cx] = true;
                        continue;
                    }
                }

                if (cx - 1 >= 0 && board1[cy][cx - 1])
                {
                    if (!BoSafe(board0, board1, cy, cx - 1))
                    {
                        board1[cy][cx] = true;
                        continue;
                    }
                }

                if (cx + 1 <= n && board1[cy][cx + 1])
                {
                    if (!BoSafe(board0, board1, cy, cx + 1))
                    {
                        board1[cy][cx] = true;
                        continue;
                    }
                }
            }
        }
        else
        {
            if (type == 0)
            {
                if (GiSafe(board0, board1, cy, cx))
                {
                    board0[cy][cx] = true;
                }
            }
            else
            {
                if (BoSafe(board0, board1, cy, cx))
                {
                    board1[cy][cx] = true;
                }
            }
        }
    }

    for(int i = 0; i <= n; ++i)
    {
	    for(int j = 0; j <= n; ++j)
	    {
		    if(board0[j][i])
                answer.push_back({ i,j,0 });
            if (board1[j][i])
                answer.push_back({ i,j,1 });
	    }
    }

    return answer;
}

int main()
{
    solution(5, { {1, 0, 0, 1},{2, 0, 0, 1},{0, 1, 1, 1},{1, 1, 1, 1},{1, 0, 0, 0} });
}
