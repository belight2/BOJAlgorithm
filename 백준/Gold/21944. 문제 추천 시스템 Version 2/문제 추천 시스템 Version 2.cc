#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <tuple>
#define X first
#define Y second
using namespace std;
const char nl = '\n';
int N,P,M,L,G,x;
string cmd;
pair<int,int> prob[100'002];
set<int> Level[102];
set<int> probGL[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  while(N--){
    cin >> P >> L >> G;
    prob[P] = {L, G};
    Level[L].insert(P);
    probGL[G][L].insert(P);
  }
  cin >> M;
  while(M--){
    cin >> cmd;
    if(cmd == "recommend"){
      cin >> G >> x;
      // x가 1이면 G에서 가장 어려운 문제 중 번호가 가장 큰 문제 출력
      // x가 -1이면 G에서 가장 쉬운 문제 중 번호가 가장 작은 문제 출력
      if(x == 1){
        for(int i = 100; i >= 0; i--){
          if(probGL[G][i].empty()) continue;
          auto it = prev(probGL[G][i].end());
          cout << *it << nl;
          break;
        }
      }
      else{
        for(int i = 0; i <= 100; i++){
          if(probGL[G][i].empty()) continue;
          auto it = probGL[G][i].begin();
          cout << *it << nl;
          break;
        }
      }
    }
    else if(cmd == "recommend2"){
      cin >> x;
      // 알고리즘 분류 상관없이 문제 번호 출력
      // x = 1, 가장 어려운 문제 중 번호가 가장 큰 문제
      // x = -1, 가장 쉬운 문제 중 번호가 가장 작은 문제
      if(x == 1){
        for(int i = 100; i >= 0; i--){
          if(Level[i].empty()) continue;
          auto it = prev(Level[i].end());
          cout << *it << nl;
          break;
        }
      }
      else{
        for(int i = 0; i <= 100; i++){
          if(Level[i].empty()) continue;
          auto it = Level[i].begin();
          cout << *it << nl;
          break;
        }
      }
    }
    else if(cmd == "recommend3"){
      int ans = -1;
      cin >> x >> L;
      if(x == 1){
        for(int i = L; i <= 100; i++){
          if(Level[i].empty()) continue;
          auto it = Level[i].begin();
          ans = *it;
          break;
        }
      }
      else{
        for(int i = L-1; i >= 0; i--){
          if(Level[i].empty()) continue;
          auto it = prev(Level[i].end());
          ans = *it;
          break;
        }
      }
      cout << ans << nl;
    }
    else if(cmd == "add"){
      cin >> P >> L >> G;
      prob[P] = {L, G};
      Level[L].insert(P);
      probGL[G][L].insert(P);
    }
    else{
      cin >> P;
      tie(L, G) = prob[P];
      Level[L].erase(P);
      probGL[G][L].erase(P);
    }
  }
}