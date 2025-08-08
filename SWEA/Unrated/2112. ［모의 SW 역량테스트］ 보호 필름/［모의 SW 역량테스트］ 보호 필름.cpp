#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int D, W, K;
int layers[13][20];
int minCount;

inline bool checkOneCol(int col)
{
    int count=1;
    int last=layers[0][col];
    for (int i = 1; i < D; ++i)
    {
        if (last==layers[i][col])
        {
            count++;
            
            if (count >= K)
            {
                return true;
            }
        }
        else
        {
            count = 1;
            last= layers[i][col];
        }
    }
    return count==K;
}

inline bool checkPerformance()
{
    for (int j = 0; j < W; ++j)
    {
        if(!checkOneCol(j))
            return false;
    }
    return true;
}


void dfs(int layerNumber, int count)
{

    if (count >= minCount)
        return;

    if (layerNumber == D)
    {

        if (checkPerformance())
        {
            minCount = min(minCount, count);
        }
        return;
    }

    dfs(layerNumber + 1, count);

    int temp[20];

    memcpy(temp, layers[layerNumber], W * sizeof(int));
    memset(layers[layerNumber], 0, W * sizeof(int));

    dfs(layerNumber + 1, count + 1);

    fill(layers[layerNumber], layers[layerNumber] + W, 1);

    dfs(layerNumber + 1, count + 1);

    memcpy(layers[layerNumber], temp, W * sizeof(int));
}

inline int solve()
{
    cin >> D >> W >> K;
    for (int i = 0; i < D; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> layers[i][j];
        }
    }

    if (checkPerformance())
    {
        return 0;
    }

    minCount = K + 1;
    dfs(0, 0);

    return minCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cout << "#" << t << " " << solve() << "\n";
    }

    return 0;
}