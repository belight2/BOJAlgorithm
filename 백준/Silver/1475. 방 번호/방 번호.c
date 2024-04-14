#include <stdio.h>
#include <string.h>
int a[10];
char n[10];
int main(){
  scanf("%[^\n]s", &n);
  int len = strlen(n);
  for(int i = 0; i < len; i++){
    int cur = n[i] - '0';
    (cur == 9) ? a[6]++ : a[cur]++;
  }
  if(a[6]&1) a[6] += 1;
  a[6] /= 2;
  int max = -1;
  for(int i = 0; i < 10; i++){
    if(max < a[i]) max = a[i];
  }
  printf("%d", max);
}