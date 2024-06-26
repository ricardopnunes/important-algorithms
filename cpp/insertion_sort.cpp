#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace sorting{

  template<typename T>
  void insertionSort(T *vetor, int n){
    for ( int i = 1; i< n; i++){
      T temp = vetor[i];
      int j = i -1;

      while ( j>=0 && temp < vetor[j]){
          vetor[j + 1] = vetor[j];
          j--;
      }
      vetor[j + 1] = temp;
    }
  }

  template<typename T>
  void insertionSort(std::vector<T> *vetor){

    size_t n = vetor->size();

    for (size_t i = 1; i< n; i++){
      T temp = vetor[0][i];
      int j = i - 1;

      while ( j >=0 && temp < vetor[0][j]){
          vetor[0][j+ 1] = vetor[0][j];
          j--;
      }
      vetor[0][j+ 1] = temp;
    }
  }
}


template <typename T>

static void criarVetorAleatorio(T *vetor, int n){
  while(n--){
    double r = (std::rand() % 10000 - 5000)/ 100.f;
    vetor[n] = static_cast<T>(r);
  }
}


void testes() {
  int arr1[10] = {78, 34, 35, 6, 34, 56, 3, 56, 2, 4};
  std::cout << "Teste 1... ";
  sorting::insertionSort(arr1, 10);
  assert(std::is_sorted(arr1, arr1 + 10));
  std::cout << "Passou!" << std::endl;

  int arr2[5] = {5, -3, 7, -2, 1};
  std::cout << "Teste 2... ";
  sorting::insertionSort(arr2, 5);
  assert(std::is_sorted(arr2, arr2 + 5));
  std::cout << "Passou!" << std::endl;

  double arr3[5] = {5.6, -3.1, -3.0, -2.1, 1.8};
  std::cout << "Teste 3... ";
  sorting::insertionSort(arr3, 5);
  assert(std::is_sorted(arr3, arr3 + 5));
  std::cout << "Passou!" << std::endl;

  std::vector<double> arr4({5.6, -3.1, -3.0, -2.1, 1.8});
  std::cout << "Teste 4... ";
  sorting::insertionSort(&arr4);
  assert(std::is_sorted(std::begin(arr4), std::end(arr4)));
  std::cout << "Passou!" << std::endl;

  int arr5[50];
  std::cout << "Teste 5... ";
  criarVetorAleatorio(arr5, 50);
  sorting::insertionSort(arr5, 50);
  assert(std::is_sorted(arr5, arr5 + 50));
  std::cout << "Passou!" << std::endl;

  float arr6[50];
  std::cout << "Teste 6... ";
  criarVetorAleatorio(arr6, 50);
  sorting::insertionSort(arr6, 50);
  assert(std::is_sorted(arr6, arr6 + 50));
  std::cout << "Passou!" << std::endl;
}

int main(){
  testes();
  return 0;
}