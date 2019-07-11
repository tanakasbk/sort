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
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
  int i, l, r, pivot;
  // 真ん中の要素をピボットとする
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;

  i = 1, l = 0, r = n-1;
  while(i<= r){
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

  if(r < k) return quick_select(A+r+1, n-r-1, k-r-1);
  else if(l > k) return quick_select(A, l, k);
  else return pivot;
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

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
    //printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
