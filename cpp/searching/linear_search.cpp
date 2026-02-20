#include <iostream>
#include <vector>
#include <cassert>



namespace searching{
    template<typename T>
    int linearSearch(const std::vector<T> &vector, const T &element){
        for(size_t i = 0; i < vector.size(); i++){
            if (vector[i] == element){
                return i;
            }
        }
        return -1;
    }
}


void tests(){

    std::vector<int> vector1 = {1,2,3,4,5};
    std::cout << "Teste 1...";
    assert(searching::linearSearch(vector1, 3) == 2);
    std::cout << "Passou!" << std::endl;

    std::vector<int> vector2 = {1,5,8,7,9,6,4,8,5,1,58,9,6,4,8,5,1};
    std::cout << "Teste 2...";
    assert(searching::linearSearch(vector2, 58) == 10);
    std::cout << "Passou!" << std::endl;

    std::vector<int> vectoo3 = {1,5,8,7,9,6,4,8,5,1,58,9,6,4,8,5,1};
    std::cout << "Teste 3...";
    assert(searching::linearSearch(vectoo3, 100) == -1);
    std::cout << "Passou!" << std::endl;

    std::vector<std::string> vectoo4 = {"abc", "def", "ghi", "jkl", "mno"};
    std::cout << "Teste 4...";
    assert(searching::linearSearch(vectoo4, std::string("mno")) == 4);
    std::cout << "Passou!" << std::endl;
    
}




int main(){
    tests();
    return 0;
}
