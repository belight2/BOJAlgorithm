#include <stdio.h>
int main(){
  int freq[10] = {0};
  int res, a, b, c;
  scanf("%d\n%d\n%d", &a, &b, &c);
  res = a * b * c;
  while(res){
    freq[res%10]++;
    res /= 10;
  }
  for(int i = 0; i < 10; i++) printf("%d\n", freq[i]);
}