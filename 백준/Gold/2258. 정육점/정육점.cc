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

// startTime: 12:08
// #1 submissionTime: 12:18

const ll MX = 0x7ffffffff;

int n, m;
vpi meat;

bool solve(ll cur) {
    bool flag{};
    ll tot{}, cost{cur}, mx{};
    for(auto &[c, w] : meat) {
        if(cur < c) continue;    
        if(!flag) {
            flag = 1;
            mx = c;
        }
        if(mx > c) {
            tot += w;
        }
        else if(mx == c && cost - c >= 0) {
            tot += w;
            cost -= c;
        } 
    }

    return tot >= m;
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int w, c;
        cin >> w >> c;
        meat.pb({c, w});
    }

    sort(rall(meat));

    ll st{}, en{MX};
    while(st + 1 < en) {
        ll md = (st + en) >> 1;
        (solve(md) ? en : st) = md;
    }

    cout << (en == MX ? -1 : en);
}