#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <string>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <chrono>
using namespace std;

void setup_io()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

int N, M;
int map[21][21];

void init()
{
    N = M = -1;
}

void input()
{
    cin >> N >> M;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> map[y][x];
        }
    }
}

int dirY[] = { 0,0,1, -1 };
int dirX[] = { 1,-1, 0,0 };

int getIncome(int K, int home)
{
    int cost=K* K + (K - 1) * (K - 1);

    return home * M - cost;
}

int bfs(int y, int x)
{
    int visit[21][21] = {0,};
    int K = 1;
    int home = 0;
    int ans = 0;

    queue<pair<int, int>> q;
    q.push({ y, x });
    visit[y][x] = 1;
    if (map[y][x] == 1)
    {
        ++home;
    }
    if (getIncome(K, home) >= 0)
    {
        ans = max(ans, home);
    }

    while (!q.empty())
    {
        K++;
        int q_size = q.size();
        for (int k = 0; k < q_size; ++k)
        {
            auto p = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ny = p.first + dirY[i];
                int nx = p.second + dirX[i];

                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                if (visit[ny][nx]) continue;

                if(map[ny][nx]==1)
                    ++home;

                visit[ny][nx] = 1;

                q.push({ ny, nx });
            }
        }
        int income = getIncome(K, home);
        if (income >= 0)
        {
            ans = max(ans, home);
        }
        
    }

    return ans;
}

void solve(int t)
{
    int ans = -1;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            ans = max(ans, bfs(y, x));
        }
    }

    cout << "#" << t << " " << ans << '\n';
}

int main(void)
{

    setup_io();

    //freopen("input.txt", "r", stdin);

    int test = 0;
    cin >> test;
    for (int t = 1; t <= test; ++t)
    {
        //cout << "#" << t + 1 << " ";
        init();
        input();
        solve(t);
    }

    return 0;
}