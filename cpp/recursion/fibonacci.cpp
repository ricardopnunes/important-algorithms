#include <iostream>
#include <vector>
#include <cassert>
#include <cstdint>
#include <stdexcept>

namespace recursion {
    constexpr unsigned int kMaxFib = 93;

    std::uint64_t fibonacci(unsigned int n){
        if( n > kMaxFib){
            throw std::overflow_error("Fibonacci: estouro de uint64_t para n > 93");
        }

        if (n < 2) return n;
        return fibonacci(n-1) + fibonacci(n - 2);
    }

    namespace detail {
        std::uint64_t fib_memo(unsigned int n, std::vector<std::uint64_t>& cache){
            if( n < 2) return n;
            if(cache[n] != 0) return cache[n];
            return cache[n] = fib_memo(n - 1, cache) + fib_memo(n - 2, cache);
        }
    }


    std::uint64_t fibonacci_memo(unsigned int n){
        if(n > kMaxFib){
            throw std::overflow_error("fibonacci_memo: estouro de uint64_t para n > 93");
        }

        std::vector<std::uint64_t> cache(n + 1, 0);
        return detail::fib_memo(n,cache);
    }
}

void tests() {

    std::cout << "Teste 1...";
    assert(recursion::fibonacci(0) == 0);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 2...";
    assert(recursion::fibonacci(1) == 1);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 3...";
    assert(recursion::fibonacci(10) == 55);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 4...";
    assert(recursion::fibonacci(30) == 832040);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 5...";
    assert(recursion::fibonacci_memo(50) == 12586269025ULL);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 6...";
    assert(recursion::fibonacci_memo(93) == 12200160415121876738ULL);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 7...";
    // as duas versoes tem que concordar
    for (unsigned int i = 0; i <= 25; ++i)
        assert(recursion::fibonacci(i) == recursion::fibonacci_memo(i));
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 8...";
    bool estourou = false;
    try {
        recursion::fibonacci_memo(94);
    } catch (const std::overflow_error&) {
        estourou = true;
    }
    assert(estourou);
    std::cout << "Passou!" << std::endl;
}


int main() {
    tests();
    return 0;
}