#include <stdio.h>
int n, x;
int a[100005];
int f[2000005];
int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  scanf("%d", &x);
  int ans = 0;
  for(int i = 0; i < n; i++){
    f[a[i]] = 1;
    if(x - a[i] < 0 || x - a[i] > 2000000) continue;
    if(f[x-a[i]] == 1 && x-a[i] != a[i]) ans++;
  }
  printf("%d", ans);
}