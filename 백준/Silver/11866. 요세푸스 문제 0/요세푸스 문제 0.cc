#include <iostream>
#include <queue>
using namespace std;
const char nl = '\n';
int n, k;
queue<int> q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  int seq = 0;
  for(int i = 1; i <= n; i++) q.push(i);
  cout << "<";
  while(q.size() > 1){
    seq = (seq+1) % k;
    if(seq != 0 ) q.push(q.front());
    else cout << q.front() <<", ";
    q.pop();
  }
  cout << q.front() << ">";
}