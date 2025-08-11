#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> grid[i][j];
        }
    }

    int happySequenceCount = 0;

    if (m == 1)
    {
        std::cout << 2 * n << std::endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        int maxConsecutiveCount = 1;
        for (int j = 1; j < n; ++j)
        {
            if (grid[i][j] == grid[i][j - 1])
            {
                maxConsecutiveCount++;
            }
            else
            {
                maxConsecutiveCount = 1;
            }

            if (maxConsecutiveCount >= m)
            {
                happySequenceCount++;
                break;
            }
        }
    }

    for (int j = 0; j < n; ++j)
    {
        int maxConsecutiveCount = 1;
        for (int i = 1; i < n; ++i)
        {
            if (grid[i][j] == grid[i - 1][j])
            {
                maxConsecutiveCount++;
            }
            else
            {
                maxConsecutiveCount = 1;
            }

            if (maxConsecutiveCount >= m)
            {
                happySequenceCount++;
                break;
            }
        }
    }

    std::cout << happySequenceCount << std::endl;

    return 0;
}