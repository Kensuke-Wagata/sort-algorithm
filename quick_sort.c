#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long partition(long *, long, long);
void quicksort(long *, long, long);

int main()
{
  long  n, i;

  scanf("%ld", &n);
  long *num = (long*)malloc(sizeof(long) * n);
  for (i = 0; i < n; i++) {
    scanf("%d", &num[i]);
  }
  
  quicksort(num, 0, n-1);
  
  for (i=0; i<n; i++){
    printf("%ld ", num[i]);
  }
  puts("");
  
  free(num);
  
  return 0;
}

void quicksort(long *a, long p, long r){
  if(p >= r) return;
  long q; 
  q = partition(a, p, r);
  quicksort(a, p, q-1);
  quicksort(a, q+1, r);
}

long partition(long *a, long p, long r)
{
  long x = a[r];
  long i = p;
  long j, tmp;

  for(j = p; j <= r - 1; j++){
    if(a[j] <= x){
      tmp = a[j];
      a[j] = a[i];
      a[i] = tmp;
      i++;
    }
  }
  tmp = a[r];
  a[r] = a[i];
  a[i] = tmp;
  return i;
}
