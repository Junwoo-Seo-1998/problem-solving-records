#include <iostream>

int main(int argc, char** argv)
{
    int T;
    std::cin >> T;

    for(int test_case = 1; test_case <= T; ++test_case)
    {

        int odd_sum = 0;

        for(int i = 0; i < 10; ++i)
        {
            int num;
            std::cin >> num; 
            if (num % 2 != 0)
            {
                odd_sum += num; 
            }
        }

        std::cout << "#" << test_case << " " << odd_sum << "\n";
    }
    return 0; 
}