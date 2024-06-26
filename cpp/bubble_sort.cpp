#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

namespace sorting{

  template<typename T>
  void bubbleSort(std::vector<T>& vetor){
    // std::sort(vetor.begin().end(), [](T a, T b) { return a < b; });
      for (size_t i = 0; i < vetor.size() -1; i++){
          for (size_t j = 0; j < vetor.size() -i -1; j++){
              if(vetor[j] > vetor[j + 1]){
                // std::swap(vetor[j][j + 1]);
                T temp = vetor[j + 1];
                vetor[j + 1] = vetor[j];
                vetor[j] = temp;  
              }
          }
      }
  }
}

s


static void testes() {
  // testcase #1
  // [1, 0, 0, 1, 1, 0, 2, 1, 8] retorna [0, 0, 0, 1, 1, 1, 1, 2, 8]
  std::vector<uint64_t> vetor1 = {1, 0, 0, 1, 1, 0, 2, 1, 8};
  std::cout << "Teste 1... ";
  sorting::bubbleSort(vetor1);
  assert(std::is_sorted(vetor1.begin(), vetor1.end()));
  std::cout << "Passou!" << std::endl;

  // testcase #2
  // [19.5, 22.5, 540.5, 241.5, 156.5, 140.5, 12.5, 1.5 ] retorna [1.5, 12.5, 19.5, 22.5, 140.5, 156.5, 241.5 ,540.5, 540.6 ]
  std::vector<double> vetor2 = {19.5, 22.5, 540.5, 241.5, 156.5, 140.5,540.6, 12.5, 1.5};
  std::cout << "Teste 2... ";
  sorting::bubbleSort(vetor2);
  assert(std::is_sorted(vetor2.begin(), vetor2.end()));
  std::cout << "Passou!" << std::endl;

  // testcase #3
  // [11, 20, 30, 41, 15, 60, 82, 15] retorna [11, 15, 15, 20, 30, 41, 60, 82]
  std::vector<uint64_t> vetor3 = {11, 20, 30, 41, 15, 60, 82, 15};
  std::cout << "Teste 3... ";
  sorting::bubbleSort(vetor3);
  assert(std::is_sorted(vetor3.begin(), vetor3.end()));
  std::cout << "Passou!" << std::endl;

  // testcase #4
  // [1, 9, 11, 546, 26, 65, 212, 14, -11] retorna [-11, 1, 9, 11, 14, 26, 65, 212, 546]
  std::vector<uint64_t> vetor4 = {1, 9, 11, 546, 26, 65, 212, 14};
  std::cout << "Teste 4... ";
  sorting::bubbleSort(vetor4);
  assert(std::is_sorted(vetor4.begin(), vetor4.end()));
  std::cout << "Passou!" << std::endl;
}

int main(){

  testes();
  return 0;
}