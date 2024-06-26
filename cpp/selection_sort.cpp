#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>


namespace sorting{

  std::vector<uint64_t> selectionSort(const std::vector<uint64_t> &vetor, uint64_t tamanho){
    std::vector<uint64_t> array(
      vetor.begin(),
      vetor.end()
    );

    for(uint64_t i =0; i< tamanho; ++i){
      uint64_t min = i;
      for (uint64_t j = i + 1; j < tamanho; ++j){
        if(array[j] < array[min]){
          min = j;
        }
      }

      if ( min != i){
        uint64_t temp = array[min];
        array[min] = array[i];
        array[i] = temp;
      }
    }

    return array;
  }
}



static void testes() {
  // testcase #1
  // [1, 0, 0, 1, 1, 0, 2, 1] retorna [0, 0, 0, 1, 1, 1, 1, 2]
  std::vector<uint64_t> vetor1 = {1, 0, 0, 1, 1, 0, 2, 1, 8};
  uint64_t vetor1tam = vetor1.size();
  std::cout << "Teste 1... ";
  std::vector<uint64_t> result_test1;
  result_test1 = sorting::selectionSort(vetor1, vetor1tam);
  assert(std::is_sorted(result_test1.begin(), result_test1.end()));
  std::cout << "Passou" << std::endl;

  // testcase #2
  // [19, 22, 540, 241, 156, 140, 12, 1] retorna [1, 12, 19, 22, 140, 156,
  // 241,540]
  std::vector<uint64_t> vetor2 = {19, 22, 540, 241, 156, 140, 12, 1};
  uint64_t vetor2tam = vetor2.size();
  std::cout << "Teste 2... ";
  std::vector<uint64_t> result_test2;
  result_test2 = sorting::selectionSort(vetor2, vetor2tam);
  assert(std::is_sorted(result_test2.begin(), result_test2.end()));
  std::cout << "Passou" << std::endl;

  // testcase #3
  // [11, 20, 30, 41, 15, 60, 82, 15] retorna [11, 15, 15, 20, 30, 41, 60, 82]
  std::vector<uint64_t> vetor3 = {11, 20, 30, 41, 15, 60, 82, 15};
  uint64_t vetor3tam = vetor3.size();
  std::cout << "Teste 3... ";
  std::vector<uint64_t> result_test3;
  result_test3 = sorting::selectionSort(vetor3, vetor3tam);
  assert(std::is_sorted(result_test3.begin(), result_test3.end()));
  std::cout << "Passou" << std::endl;

  // testcase #4
  // [1, 9, 11, 546, 26, 65, 212, 14, -11] retorna [-11, 1, 9, 11, 14, 26, 65,
  // 212, 546]
  std::vector<uint64_t> vetor4 = {1, 9, 11, 546, 26, 65, 212, 14};
  uint64_t vetor4tam = vetor4.size();
  std::cout << "Teste 4... ";
  std::vector<uint64_t> result_test4;
  result_test4 = sorting::selectionSort(vetor4, vetor4tam);
  assert(std::is_sorted(result_test4.begin(), result_test4.end()));
  std::cout << "Passou" << std::endl;
}

int main(){

  testes();
  return 0;
}