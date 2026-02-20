#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>


namespace sorting
{
  void merge(int *arr, int left, int meio ,int right){
    int i,j,k;
    int n1 = meio - left + 1;
    int n2 = right - meio;
  
    std::vector<int> Left(n1), Right(n2);
  
    
    for (i = 0; i < n1; ++i) Left[i]  = arr[left + i];
    for (j = 0; j < n2; ++j) Right[j] = arr[meio + 1 + j];
    
    std::cout << Left[0] << " " << Right[0] << std::endl;
    
    i = 0;
    j = 0;
    k = left;
  
    while (i < n1 && j < n2){
      if (( Left[i] <= Right[j])) arr[k++] = Left[i++];
      else arr[k++] = Right[j++];
    }
  
    while (i < n1) arr[k++] = Left[i++];
    while (j < n2) arr[k++] = Right[j++];
  }
  
  
  void mergeSort(int arr[], int left,int right){
    std::cout << "left: " << left << " right: " << right << std::endl;
    if (left < right){
      int meio = left + (right-left) / 2;
      std::cout << "meio: " << meio << std::endl;
      mergeSort(arr, left, meio);
      mergeSort(arr, meio + 1, right);
      merge(arr, left, meio, right);
    }
  }  
}

void show(int *arr, int size){
  for(int i =0; i<size;i++) std::cout<<arr[i] << " "; 
  std::cout << "\n ";
}

void testes(){

    std::cout << "Teste 1... ";
    int arr1[] = {15,18,10,5,8,2,3,6,9,1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    sorting::mergeSort(arr1, 0, size1 - 1);
    assert(std::is_sorted(arr1, arr1 + size1) == true);
    std::cout << "Passou!" << std::endl;
}


int main() {
    
  testes();
  return 0;
}