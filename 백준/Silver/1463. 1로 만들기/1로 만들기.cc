#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>


using namespace std;

int dp[1000001];



int dfs(int num) {
    if (dp[num] != -1)
        return dp[num];

    if (num == 1) {
        return 0;
    }

    int subMin = dfs(num - 1) + 1;

    if (num % 2 == 0) {
        subMin = min(dfs(num / 2) + 1, subMin);
    }
    if (num % 3 == 0) {
        subMin = min(dfs(num / 3) + 1, subMin);
    }

    return dp[num] = subMin;
}

inline int dpFor(int n)
{
    dp[1] = 0;

    for (int num = 2; num <= n; ++num)
    {
        int subMin = dp[num - 1] + 1;
        if (num % 2 == 0) {
            subMin = min(dfs(num / 2) + 1, subMin);
        }
        if (num % 3 == 0) {
            subMin = min(dfs(num / 3) + 1, subMin);
        }
        dp[num] = subMin;
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    memset(dp, -1, sizeof(dp));

    int answer = dpFor(N);

    cout << answer << "\n";

    return 0;
}