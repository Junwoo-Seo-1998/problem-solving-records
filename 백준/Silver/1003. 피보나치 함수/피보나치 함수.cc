#include <iostream>
#include <array>
#include <utility>

template<int N>
struct Fibonacci {
    static constexpr long long value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template<>
struct Fibonacci<0> {
    static constexpr long long value = 0;
};

template<>
struct Fibonacci<1> {
    static constexpr long long value = 1;
};

template<std::size_t... I>
constexpr std::array<long long, sizeof...(I)> make_fib_array_impl(std::index_sequence<I...>) {
    return { Fibonacci<I>::value... };
}

constexpr auto make_fib_array() {
    return make_fib_array_impl(std::make_index_sequence<41>{});
}

constexpr auto fiboarr = make_fib_array();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--)
    {
        int n;
        std::cin >> n;
        if (n == 0)
            std::cout << "1 0\n";
        else
            std::cout << fiboarr[n - 1] << ' ' << fiboarr[n] << '\n';
    }

    return 0;
}