#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <cassert>

namespace recursion {
    constexpr unsigned  int kMaxFactorial = 20;

    std::uint64_t factorial(unsigned int n){
        if(n > kMaxFactorial){
            throw std::overflow_error("factorial: estouro de uint64_t para n > 20");
        }

        if(n <= 1) return 1;
        
        return n* factorial(n -1);
    }
}


void tests() {

    std::cout << "Teste 1...";
    assert(recursion::factorial(0) == 1);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 2...";
    assert(recursion::factorial(1) == 1);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 3...";
    assert(recursion::factorial(5) == 120);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 4...";
    assert(recursion::factorial(12) == 479001600ULL);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 5...";
    assert(recursion::factorial(20) == 2432902008176640000ULL);
    std::cout << "Passou!" << std::endl;

    std::cout << "Teste 6...";
    bool estourou = false;
    try {
        recursion::factorial(21);
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