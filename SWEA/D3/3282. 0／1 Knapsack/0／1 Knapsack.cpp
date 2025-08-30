#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
int N, K;

int volumes[102];
int values[102];

int dp[102][1002];

inline void init()
{
    memset(dp, -1, sizeof(dp));
}


inline void input()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> volumes[i];
        cin >> values[i];
    }
}

int Knapsack(int cur, int volume)
{
    if (dp[cur][volume] != -1)
        return dp[cur][volume];

    if (cur == N)
        return dp[cur][volume] = 0;

    int maxValue = Knapsack(cur + 1, volume);

    if (volume - volumes[cur] >= 0)
        maxValue = max(Knapsack(cur + 1, volume - volumes[cur]) + values[cur], maxValue);


    return dp[cur][volume] = maxValue;
}


inline void solution(int test)
{
    cout << '#' << test << ' ' << Knapsack(0, K) << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        init();
        input();
        solution(t);
    }

    return 0;
}