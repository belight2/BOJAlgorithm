#include <stdio.h>
#define inf 1000000005

int n, m;
int tree[200005];

int min(int a, int b){ return (a < b) ? a : b; }

int rmq(int l, int r){
  int ret = inf;
  for( l += n, r += n; l < r; l>>=1, r>>=1){
    if(l&1) ret = min(ret, tree[l++]);
    if(r&1) ret = min(ret, tree[--r]);
  }
  return ret;
}

int main(){
  scanf("%d %d ", &n, &m);
  for(int i = 0; i < n; i++) scanf("%d ", &tree[i+n]);
  for(int i = n-1; i > 0; i--) tree[i] = min(tree[i<<1], tree[i<<1|1]);

  while(m--){
    int a, b;
    scanf("%d %d ", &a, &b);
    printf("%d\n", rmq(a-1, b));
  } 
}