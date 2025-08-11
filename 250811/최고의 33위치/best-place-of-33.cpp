#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> grid(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> grid[i][j];
        }
    }

    int max_coins = 0;
    for (int i = 0; i <= N - 3; ++i) {
        for (int j = 0; j <= N - 3; ++j) {
            
            int current_coins = 0;

           
            for (int row = i; row < i + 3; ++row) 
            {
                for (int col = j; col < j + 3; ++col) 
                {
                    current_coins += grid[row][col];
                }
            }

            max_coins = std::max(max_coins, current_coins);
        }
    }
    std::cout << max_coins << std::endl;

    return 0;
}