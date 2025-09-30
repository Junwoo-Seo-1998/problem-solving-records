#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int Floors, Height, Width;

char building[30][30][30];

int dirZ[] = { 0,0,0,0, 1, -1};
int dirY[] = { 0,0,1, -1,0,0 };
int dirX[] = { 1,-1,0,0, 0,0 };

struct state
{
    int z;
    int y;
    int x;
};

state start;
state goal;

inline void init()
{
    cin >> Floors >> Height >> Width;

    for (int f = 0; f < Floors; ++f)
    {
        for (int h = 0; h < Height; ++h)
        {
            for (int w = 0; w < Width; ++w)
            {
                cin >> building[f][h][w];
                if (building[f][h][w] == 'S')
                {
                    start = { f,h,w };
                    building[f][h][w] = '.';
                }
                else if (building[f][h][w] == 'E')
                {
                    goal = { f,h,w };
                    building[f][h][w] = '.';
                }
            }
        }
    }
}

inline void solve()
{
    //bfs
    int tookTime[30][30][30];
    memset(tookTime, -1, sizeof(tookTime));

    queue<state> q;
    q.push(start);
    tookTime[start.z][start.y][start.x] = 0;

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();

        if (cur.x == goal.x && cur.y == goal.y && cur.z == goal.z)
            break;

        for (int i = 0; i < 6; ++i)
        {
            int nextZ = cur.z + dirZ[i];
            int nextY = cur.y + dirY[i];
            int nextX = cur.x + dirX[i];

            if (nextZ < 0 || nextZ >= Floors || nextY < 0 || nextY >= Height || nextX < 0 || nextX >= Width) continue;
            if (building[nextZ][nextY][nextX] == '#') continue;
            if (tookTime[nextZ][nextY][nextX] != -1) continue;

            tookTime[nextZ][nextY][nextX] = tookTime[cur.z][cur.y][cur.x] + 1;

            q.push({ nextZ, nextY, nextX });
        }
    }

    if (tookTime[goal.z][goal.y][goal.x] != -1)
    {
        cout << "Escaped in " << tookTime[goal.z][goal.y][goal.x] << " minute(s).\n";
    }
    else
    {
        cout << "Trapped!\n";
    }
}
int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    
    while(true)
    {
        init();
        if (Floors == 0) break;

        solve();
    }

    return 0;
}