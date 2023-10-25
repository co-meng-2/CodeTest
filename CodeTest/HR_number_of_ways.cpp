#include <algorithm>
#include <vector>
using std::vector;
#include <iostream>

int numberOfWays(vector<vector<int>> roads)
{
    int adjMat[51][51]{};

    int INF = 1000000000;
    for(int i = 0; i < 51; ++i)
    {
	    for(int j = 0; j < 51; ++j)
	    {
            adjMat[51][51] = INF;
	    }
    }

    for (int i = 0; i < roads.size(); ++i)
    {
        adjMat[roads[i][0]][roads[i][1]] = 1;
        adjMat[roads[i][1]][roads[i][0]] = 1;
    }

    // prim
    for (int k = 1; k < 51; ++k)
    {
        for (int i = 1; i < 51; ++i)
        {
            for (int j = 1; j < 51; ++j)
            {
                adjMat[i][j] = std::min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
            }
        }
    }

    int ret = 0;
    // 세 쌍을 찾는다.
    for (int i = 1; i < 51; ++i)
    {
        for (int j = i + 1; j < 51; ++j)
        {
            for (int k = j + 1; k < 51; ++k)
            {
                if (adjMat[i][j] != 0 && adjMat[i][j] == adjMat[j][k] && adjMat[j][k] == adjMat[k][i])
                    ret++;
            }
        }
    }

    return ret;
}

int main()
{
    int road_size = 0;
    int trash = 0;
    std::cin >> road_size;
    std::cin >> trash;
    vector<vector<int>> input(road_size);

    for(int i = 0; i < road_size; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        input[i].push_back(x);
        input[i].push_back(y);
    }

    int ans = numberOfWays(input);
}
