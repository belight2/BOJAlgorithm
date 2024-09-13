// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using tl = tuple<ll, ll, ll>;

int n;
ll init_attack;
vector<tl> room;

bool solve(ll maxHP){
  ll curHP = maxHP;
  ll cur_attack_power = init_attack;
  
  for(int i = 0; i < n; i++){
    auto &[room_type, attack_power, HP] = room[i];
    if(room_type){ // 휴식방
      curHP += HP;
      cur_attack_power += attack_power;
      if(curHP > maxHP) curHP = maxHP;
    }
    else{
      int game_turn = HP / cur_attack_power + ((HP % cur_attack_power) ? 1 : 0); // 만약 나머지값이 있다면, turn을 한 번 더 진행해야 함
      curHP -= attack_power * (game_turn - 1); // game의 turn-1번 동안 몬스터에게 피해를 입는다.     
      if(curHP <= 0) return 0; // 몬스터에게 피해를 입고 현재 체력이 0 아래로 내려가 죽는다.
    }
  }

  // 모든 방을 클리어하였음.
  return 1;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> init_attack;
  room.resize(n);
  for(auto &[type, attack_power, HP] : room){
    cin >> type >> attack_power >> HP;
    type--;
  }

  // solve
  ll st{}, en = 1e18;
  while(st < en){
    ll mid = (st+en+1)>>1;
    (solve(mid) ? en = mid-1 : st = mid);
  }

  // output
  cout << en+1;
}