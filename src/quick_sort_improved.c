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
    int pivot, i, j, k;
    pivot = A[0];
    for(i = j = k = 1; i < n; i++){
        if(A[i] < pivot){
          swap(A + i, A + j);
          j++;
          k++;
        }else if(A[i] == pivot){
          k++;
        }
    }
    swap(A + j - 1, A);
    if(j > 2)quick_sort(A, j - 1);
    if(k < n)quick_sort(A + k, n - k);
}

int main(){
  int i;
/*
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
*/

// すべての要素が同じ場合でも計算が早く終わるか確認する
    for(i=0;i<N;i++){
        A[i] = 17;
    }

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
