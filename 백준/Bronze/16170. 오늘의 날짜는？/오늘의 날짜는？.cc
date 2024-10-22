// Authored by : chjh2129
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  time_t t = time(nullptr);

  tm* now = localtime(&t);

  cout << (now->tm_year + 1900) << '\n' << (now->tm_mon + 1) << '\n' << (now->tm_mday);
}