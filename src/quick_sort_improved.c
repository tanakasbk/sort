#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
  int pivot, i, l, r;
  pivot = A[0];

  i = 1, l = 0, r = n-1;
  while(i <= r){
    if(A[i] < pivot){
      swap(A+i, A+l);
      l++;
      i++;
    }else if(A[i] > pivot){
      swap(A+i, A+r);
      r--;
    }else{
      i++;
    }
  }
  
  if(l > 1)quick_sort(A, l);
  if(r < n-2)quick_sort(A+r+1, n-r-1);
}

int main(){
  int i;

  // A[0] = 0;
  // A[1] = 17; //原始元
  // for(i=2;i<N;i++){
  //   A[i] = (long long int) A[i-1] * A[1] % N;
  // }


// すべての要素が同じ場合でも計算が早く終わるか確認する
    for(i=0;i<N;i++){
        A[i] = 17;
    }

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
