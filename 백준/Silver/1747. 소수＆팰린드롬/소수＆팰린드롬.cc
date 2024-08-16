#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string str){
  int st = 0, en = int(str.size()) - 1;
  while(st < en){
    if(str[st++] != str[en--]) return 0;
  }
  return 1;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  vector<bool> is_prime(2'000'001, 1);
  is_prime[0] = is_prime[1] = 0;
  for(int i = 2; i * i <= 2'000'000; i++){
    if(!is_prime[i]) continue;
    for(int j = i * i; j <= 2'000'000; j+=i) is_prime[j] = 0;
  }

  int n;
  cin >> n;

  for(int i = n; i <= 2'000'000; i++){
    if(is_prime[i] && is_palindrome(to_string(i))){
      cout << i << " ";
      return 0;
    }
  }
}