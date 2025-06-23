#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int solution(vector<vector<int>> info, int n, int m) {
    vector<int> dp(n + 1, INF);

    dp[0] = 0;


    for (const auto& item : info) {
        int a_cost = item[0];
        int b_cost = item[1];

        for (int j = n - 1; j >= 0; --j) {

            if (dp[j] == INF) {
                continue;
            }

            if (j + a_cost < n) {

                dp[j + a_cost] = min(dp[j + a_cost], dp[j]);
            }

            if (dp[j] + b_cost < m) {
                dp[j] = dp[j] + b_cost;
            } else {
                dp[j] = INF;
            }
        }
    }

    for (int j = 0; j < n; ++j) {
        if (dp[j] < m) {
            return j;
        }
    }

    return -1;
}