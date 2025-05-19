#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    vector<unordered_set<int>> dp(9); // dp[1]~dp[8] 사용

    for (int i = 1; i <= 8; ++i) {
        // N을 i번 이어붙인 수 예: 5, 55, 555
        int num = 0;
        for (int j = 0; j < i; ++j)
            num = num * 10 + N;
        dp[i].insert(num);
        if (num == number) return i;

        for (int j = 1; j < i; ++j) {
            for (int op1 : dp[j]) {
                for (int op2 : dp[i - j]) {
                    dp[i].insert(op1 + op2);
                    dp[i].insert(op1 - op2);
                    dp[i].insert(op1 * op2);
                    if (op2 != 0) dp[i].insert(op1 / op2);
                }
            }
        }

        if (dp[i].count(number)) return i;
    }

    return -1;
}