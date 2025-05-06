#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(n, vector<int>(m, 0));
    map[0][0] = 1;

    for(vector<int>& v : puddles)
    {
        map[v[1] - 1][v[0] - 1] = -1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == 0 && j == 0)
                continue;
            
            if(map[i][j] == -1)
                continue;
            
            int count = 0; 
            if(i - 1 >= 0 && map[i - 1][j] != -1)
            {
                count += map[i - 1][j];
            }

            if(j - 1 >= 0 && map[i][j - 1] != -1)
            {
                count += map[i][j - 1];
            }
            map[i][j] = count % 1000000007;
        }
    }

    return map[n - 1][m - 1];
}