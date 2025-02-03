#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
#define pb push_back
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

int n, k;
deque<pi> belt;

void get_off_on_belt() {
    belt[n - 1].Y = 0;
}

void rotate() {
    belt.push_front(belt.back());
    belt.pop_back();
    get_off_on_belt();
}

void put_on_robot() {
    auto &[hp, exists_robot] = belt.front();
    if(hp <= 0) return; 
    hp--;
    exists_robot = 1;
}

void move_robot() {
    for(int i = n - 1; i > 0; i--) {
        auto &[cur, cur_robot] = belt[i];
        if(cur <= 0 || cur_robot) continue;
        
        auto &[prv, prv_robot] = belt[i - 1];
        if(!prv_robot) continue;
        cur--;
        prv_robot = 0;
        cur_robot = 1;
    }
    get_off_on_belt();
}

void chk_durability() {
    for(int i = 0; i < n; i++) {
        if(belt[i].X == 0) {
            belt[i].X = -1;
            k--;
        }
    }
}


int main() {
    fastio(nullptr, false);

    cin >> n >> k;
    deque<pi> (n << 1).swap(belt);
    for(auto &[x, y] : belt) cin >> x;

    int ans{};
    while(k > 0) {
        ans++;
        rotate();
        move_robot();
        put_on_robot();
        chk_durability();
    }

    cout << ans;
}