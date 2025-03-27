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

int mx{};
vector<vi> player(11, vi(11));
vb isused(11);

void func(int idx, int score) {
    if(idx == 11) {
        mx = max(mx, score);
        return;
    }

    for(int i = 0; i < 11; i++) {
        if(!isused[i] && player[i][idx]) {
            isused[i] = 1;
            func(idx + 1, score + player[i][idx]);
            isused[i] = 0;
        }
    }
}

void solve(int tc) {
    for(auto &x : player) {
        for(auto &y : x) {
            cin >> y;
        }
    }   

    mx = 0;
    func(0, 0);

    cout << mx << nl;
}

int main() {
    fastio(nullptr, false);
    int tc{};
    cin >> tc;
    for(int i = 1; i <= tc; i++) solve(i);
}