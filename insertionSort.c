#include <stdio.h>

int main(void) {
  int i,j,key;
  int a[] = {9,2,8,5,1};
  
  for(i = 1; i < 5; i++)
  {
    key = a[i];
    j = i -1;
    while((j >= 0) && (a[j] > key)) // Compare key and previous value
    {
      a[j + 1] = a[j];  //Move
      j--;
    }
    a[j+ 1] = key; // Insert
  }

  int k;
  for(k = 0; k < 5; k++)
  {
    printf("a[%d] = %d\n", k , a[k]);
  }

  return 0;
}