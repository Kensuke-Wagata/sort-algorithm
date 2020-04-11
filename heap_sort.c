#include<stdio.h>
#include<stdlib.h>

void printArray(int *, int);
void swap(int *, int *);
void create_heap(int *, int , int);
void heapsort(int *, int);

void printArray(int* array, int size) {
     int i;
     for (i = 0; i < size; i++) {
       printf("%d ", array[i]);
     }
     printf("\n");     return;
}

void swap (int *x, int *y) {
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}

void create_heap(int *array, int children, int parent)
{
  int i;
  for(i = children; i >= 0; i--){
    printf("%d\n", i);
    while(i != 0){
     parent = i /2;
     if(array[parent] > array[i]) break;
     else{
       swap(&array[parent], &array[i]);
       i  =  parent;
     }
   }
  }
   
}

void heapsort (int *array, int members) {
  int children = members;
  int parent = (children - 1) /2;
  int i = 0, j = 0;

 
  while(children > 0){
    create_heap(array, children, parent);
    children--;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int* array = (int*) malloc(sizeof(int) * n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }
  heapsort(array, n - 1);
  printArray(array, n);
  return 0;
}
