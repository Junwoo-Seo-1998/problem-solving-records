#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>


using namespace std;

int dp[15];
int N;
int ans = 0;


int dfs(int num) {
    if (dp[num] != -1) return dp[num];

    if (num <= 0)
        return 0;
    if (num == 1)
        return 1;
    if (num == 2)
        return 2;
    if (num == 3)
        return 4;
    
    int subAns = 0;
    subAns += dfs(num - 1);
    subAns += dfs(num - 2);
    subAns += dfs(num - 3);

    return dp[num]=subAns;
}

inline int dpFor(int n)
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int num = 4; num <= n; ++num)
    {
        dp[num] = dp[num - 1] + dp[num - 2] + dp[num - 3];
    }

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {

        memset(dp, -1, sizeof(dp));

        int input; cin >> input;
        int ans = dpFor(input);
        cout << ans << "\n";
        
    }

    

    //int answer=dfs(N);


    

    return 0;
}