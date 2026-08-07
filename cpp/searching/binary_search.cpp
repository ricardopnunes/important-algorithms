#include <iostream>
#include <vector>
#include <cassert>
#include <cstddef>


// Implementacao de uma busca binaria
namespace searching {

    template <typename T>
    std::ptrdiff_t binary_search(const std::vector<T>& arr, const T& alvo){
        std::ptrdiff_t low = 0;
        std::ptrdiff_t high = static_cast<std::ptrdiff_t>(arr.size()) -1;

        while(low <= high){
            std::ptrdiff_t mid = low + (high - low) / 2;
            if (arr[mid] == alvo)       return mid;
            else if (arr[mid] < alvo)   low = mid + 1;
            else                        high = mid - 1;
        }
        return -1;
    }
}


void tests(){

    std::vector<int> vector1 = {1,2,3,4,5};
    std::cout << "Teste 1...";
    assert(searching::binary_search(vector1, 3) == 2);
    std::cout << "Passou!" << std::endl;

    std::vector<int> vector2 = {1,5,8,7,9,6,4,8,5,1,58,9,6,4,8,5,1};
    std::cout << "Teste 2...";
    assert(searching::binary_search(vector2, 58) == -1);
    std::cout << "Passou!" << std::endl;

    std::vector<int> vectoo3 = {1,5,8,7,9,6,4,8,5,1,58,9,6,4,8,5,1};
    std::cout << "Teste 3...";
    assert(searching::binary_search(vectoo3, 100) == -1);
    std::cout << "Passou!" << std::endl;

    std::vector<std::string> vectoo4 = {"abc", "def", "ghi", "jkl", "mno"};
    std::cout << "Teste 4...";
    assert(searching::binary_search(vectoo4, std::string("mno")) == 4);
    std::cout << "Passou!" << std::endl;
    
}

int main(){
    tests();
    return 0;
}