#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

void merge(int *arr, int left, int meio ,int right){
  int i,j,k;
  int n1 = meio - left + 1;
  int n2 = right - meio;

  int *Left = new int[n1], *Right = new int[n2];

  for (i = 0; i < n1; i++) Left[i]  = arr[left + i];
  for (j = 0; j < n2; j++) Right[j] = arr[meio + 1 + j];

  i = 0;
  j = 0;
  k = left;

  while (i < n1 || j < n2){
    if (j >= n2 || (i < n1 && Left[i] <= Right[j])){
      arr[k] = Left[i];
      i++;
    }else{
      arr[k] = Right[j];
      j++;
    }
    k++;
  }

  delete[] Left;
  delete[] Right;

}

void mergeSort(int *arr, int right, int left){
  if (left < right){
    int meio = left + (right-left) / 2;
    mergeSort(arr, left, meio);
    mergeSort(arr, meio + 1, right);
    merge(arr, left, meio, right);
  }
}

void show(int *arr, int size){
  for(int i =0; i<size;i++) std::cout<<arr[i] << " "; 
  std::cout << "\n ";
}

int main() {
    int size;
    std::cout << "Enter the number of elements : ";
    std::cin >> size;
    int *arr = new int[size];
    std::cout << "Enter the unsorted elements : ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    mergeSort(arr, 0, size - 1);
    std::cout << "Sorted array : ";
    show(arr, size);
    delete[] arr;
    return 0;
}