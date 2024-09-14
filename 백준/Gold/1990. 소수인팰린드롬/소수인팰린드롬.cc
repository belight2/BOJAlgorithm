// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int a, b;
vector<int> prime;

// a부터 b사이의 소수를 구한다.
void eratos(){
  vector<bool> isprime(b+1, 1);
  for(int i = 2; i * i <= b; i++){
    if(!isprime[i]) continue;
    for(int j = i * i; j <= b; j+=i){
      isprime[j] = 0;
    }
  }
  for(int i = a; i <= b; i++) if(isprime[i]) prime.push_back(i);
}

// 매개 변수 str이 palindrome인지 확인한다.
bool is_palindrome(const string &str){
  int st{}, en = (int)str.size() - 1;
  while(st < en){
    if(str[st++] != str[en--]) return 0;
  }  
  return 1;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> a >> b;

  // solve & output
  eratos();
  for(auto &val : prime){
    if(is_palindrome(to_string(val))) cout << val << '\n';
  }
  cout << -1;
}