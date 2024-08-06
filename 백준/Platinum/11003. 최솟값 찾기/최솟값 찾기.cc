#include <bits/stdc++.h>

using namespace std;

int n, l;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> l;

  vector<int> a(n);
  for(auto &x : a) cin >> x;

  deque<int> dq;
  for(int i = 0; i < n; i++){
    if(dq.size() && i - dq.front() == l) dq.pop_front();
    while(dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
    dq.push_back(i);
    cout << a[dq.front()] << " ";
  }
}