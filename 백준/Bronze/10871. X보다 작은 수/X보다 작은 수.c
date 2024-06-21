#include <stdio.h>
int main(){
  int n, x, a;
  scanf("%d %d", &n, &x);
  while(n--){
    scanf(" %d", &a);
    if(a >= x) continue;
    printf("%d ", a);
  }
}