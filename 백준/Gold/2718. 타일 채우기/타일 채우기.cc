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

int n;
ll d[22];

ll cal(int idx) {
    if(idx == 0) {
        return 1;
    }
    if(d[idx] != -1) {
        return d[idx];
    }

    d[idx] = cal(idx - 1) + 4 * cal(idx - 2);    
    for(int k = idx - 3; k >= 0; k--) {
        d[idx] += ((idx - k) & 1 ? 2 : 3) * cal(k);
    }  
    return d[idx];
}

void solve(int tc) {
    cin >> n;
    cout << cal(n) << nl;
}

int main() {
    fastio(nullptr, false);
    int tc{};
    cin >> tc;
    memset(d, 0xff, sizeof(d));
    d[0] = 1; d[1] = 1; d[2] = 5;
    cal(21);
    for(int i = 1; i <= tc; i++) solve(i);   
}