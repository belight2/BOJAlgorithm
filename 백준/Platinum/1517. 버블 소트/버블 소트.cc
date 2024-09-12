#include <bits/stdc++.h>

using namespace std;

int n;
int a[500'005];
long long ans;

void merge(int st, int mid, int en){
  vector<int> v;
  int i = 0, j = 0, len1 = mid - st, len2 = en - mid;
  while(i < len1 && j < len2){
    if(a[st+i] > a[mid+j]){
      ans += len1 - i;
      v.push_back(a[mid+j++]);
    }
    else v.push_back(a[st+i++]);
  }
  while(i < len1) v.push_back(a[st+i++]);
  while(j < len2) v.push_back(a[mid+j++]);
  for(int i = st; i < en; i++) a[i] = v[i-st];
}
void merge_sort(int st, int en){
  if(en == st + 1) return;
  if(en == st + 2){
    if(a[st] > a[st+1]){
      ans++;
      swap(a[st], a[st+1]);
    }
    return;
  }
  int mid = (st + en) / 2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, mid, en);
}
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  merge_sort(0, n);
  cout << ans;
}