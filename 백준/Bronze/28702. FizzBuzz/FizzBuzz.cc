#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string line;
ll num;
bool flag;
bool is_number(const string &str){
  return regex_match(str, regex("^[0-9]+$"));
}
void is_fizz_buzz(ll num){
  if(num % 15 == 0) cout << "FizzBuzz";
  else if(num % 3 == 0) cout << "Fizz";
  else if(num % 5 == 0) cout << "Buzz";
  else cout << num;
}
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  for(int i = 0; i < 3; i++){
    cin >> line;
    if(flag) num++;
    else if(flag = is_number(line), flag) num = stoll(line);  
  } 
  is_fizz_buzz(num+1);
}