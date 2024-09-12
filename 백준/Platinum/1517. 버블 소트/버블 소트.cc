#include <bits/stdc++.h>

using namespace std;

long long swap_count;
int n;
int a[500'005];
int tmp[500'005];

void merge(int st, int en){
  int mid = (st+en)>>1;
  int lidx = st, ridx = mid;
  for(int i = st; i < en; i++){
    if(lidx >= mid) tmp[i] = a[ridx++];
    else if(ridx >= en) tmp[i] = a[lidx++];
    else if(a[lidx] > a[ridx]){
      swap_count += mid - lidx;
      tmp[i] = a[ridx++];
    }
    else tmp[i] = a[lidx++];
  }
  
  for(int i = st; i < en; i++) a[i] = tmp[i];
}

void merge_sort(int st, int en){
  if(en == st+1) return;
  int mid = ((st+en)>>1);
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, en);
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  // input
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  merge_sort(0, n);

  cout << swap_count;
}