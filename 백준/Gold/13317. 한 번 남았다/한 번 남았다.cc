#include <cstdio>

int main(){
  int n = 50, m = 49;
  printf("%d %d\n", n, m);

  int t1 = 49, t2 = 50, t3 = -1;
  while(m--){
    printf("%d %d %d\n", t1--, t2--, t3);
  }
}