#include <iostream>
#include <array>

using namespace std;

constexpr long long factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

constexpr std::array<long long, 13> generateFactorialTable()
{
    std::array<long long, 13> table{};
    for (int i = 0; i < 13; ++i)
    {
        table[i] = factorial(i);
    }
    return table;
}
constexpr auto precomputedFactorials = generateFactorialTable();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nValue;
    cin >> nValue;

    cout << precomputedFactorials[nValue] << "\n";

    return 0;
}