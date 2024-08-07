#include <bits/stdc++.h>

using namespace std;

class compare{
  public:
    bool operator()(const int &a, const int &b){
      if(abs(a) != abs(b)) return abs(a) > abs(b);
      return a > 0 && b < 0;
    }
};
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  priority_queue<int, vector<int>, compare> pq;
  int n;

  cin >> n;

  while(n--){
    int x;

    cin >> x;

    if(x) pq.push(x);
    else if(pq.empty()) cout << "0\n";
    else{
      cout << pq.top() << '\n';
      pq.pop();
    }
  }
}