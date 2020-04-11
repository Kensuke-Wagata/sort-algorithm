#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int* array, int size) {
     int i;
     for (i = 0; i < size; i++) {
       printf("%d ", array[i]);
     }
     printf("\n");     return;
}

void copyArray(int* from, int* to, int to_size, int start) {
  int i = 0, k = 0;
  for (i = 0; i < to_size - 1; i++) {
    to[i] = from[start + k];
    k++;
  }
  to[to_size - 1] = INT_MAX;
  return;
 }

void sortArray(int* array, int* left, int* right, int start, int end) {
  int i = 0, j = 0, k = 0;
  for (k = 0; k < end - start + 1; k++) {
    if (left[i] <= right[j]) {
      array[start + k]  = left[i];
      i++;
    } else {
      array[start + k]  = right[j];
      j++;
    }
  }
  return;
 }

// 統治操作
void conquer(int* array, int start, int middle, int end) {
  int left_size = middle - start + 2;
  int* left = (int*) malloc(sizeof(int) * left_size);
  int right_size = end - middle + 1;
  int* right = (int*) malloc(sizeof(int) * right_size);
  copyArray(array, left, left_size, start);
  copyArray(array, right, right_size, middle + 1);
  sortArray(array, left, right, start, end);
  free(left);
     free(right);
     return;
}

// マージソートする
void mergeSort(int* array, int start, int end) {
  int middle = (start + end) / 2;
  int left_start = start;
  int left_end = middle;
  int right_start = middle + 1;
  int right_end = end;
  if (left_start != left_end) {
        mergeSort(array, left_start, left_end);
  }
  if (right_start != right_end) {
    mergeSort(array, right_start, right_end);
  }
  conquer(array, start, middle, end);
    return;
}

int main() {
  int n;
  scanf("%d", &n);
  int* array = (int*) malloc(sizeof(int) * n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }
  mergeSort(array, 0, n - 1);
  printArray(array, n);
  return 0;
}

