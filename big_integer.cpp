#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <exception>

class BigIntegerOverflow : public std::exception {
    const char* what() const noexcept override {
        return "Result is too large";
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    BigInteger a, b;
    std::cin >> a >> b;
    int c;
    std::cin >> c;

    std::cout << (a * c == c * (--b)++) << '\n';
    std::cout << (a + 5 < (++b)--) << '\n';
    std::cout << (a <= b) << '\n';
    std::cout << (a > b - 5) << '\n';
    std::cout << (a >= b - 5) << '\n';
    std::cout << (a != b * c) << '\n';
    std::cout << (a == -b) << '\n';

    BigInteger d("123"), e(1ULL << 63);
    std::cout << (d + c) * e << '\n';

    try {
        a += b;
        b = a - b;
        a -= b;
        std::cout << a + b << '\n';
        std::cout << a - b << '\n';
        std::cout << a * b << '\n';
    } catch (BigIntegerOverflow& ex) {
        std::cout << "Overflow" << '\n';
    }
    return 0;
}

