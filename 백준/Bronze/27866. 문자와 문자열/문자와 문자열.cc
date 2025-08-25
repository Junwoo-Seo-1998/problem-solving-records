#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string S;
    int i;
    std::cin >> S >> i;
    std::cout << S[i - 1];

    return 0;
}