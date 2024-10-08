// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  int n; // 명령어 개수
  int head = 0; // 큐에 앞부분의 index
  vector<int> v; // 큐로 사용할 벡터
  // 큐는 v[head] ~ v[v.size() - 1]까지를 원소로 가짐

  cin >> n; //입력
  while(n--){
    string command;
    cin >> command; //명령어 입력

    // push 명령어 수행
    if(command == "push"){
      int x;
      cin >> x;
      v.push_back(x);
    }
    // pop 명령어 수행
    else if(command == "pop"){
      if(head == v.size()) cout << -1 << '\n';
      else{
        cout << v[head] << '\n';
        head++;
      } 
    }
    // size 명령어 수행
    else if(command == "size"){
      cout << v.size() - head << '\n';
    }
    // empty 명령어 수행
    else if(command == "empty"){
      if(head == v.size()) cout << 1 << '\n';
      else cout << 0 << '\n';
    }
    // front 명령어 수행
    else if(command == "front"){
      if(head == v.size()) cout << -1 << '\n';
      else cout << v[head] << '\n';
    }
    // back 명령어 수행
    else if(command == "back"){
      if(head == v.size()) cout << -1 << '\n';
      else cout << v[v.size() -1] << '\n';
    }
  }
}