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

int move_forward(int x) {
    return x + 1;
}

int move_backward(int x) {
    return x - 1;
}

int teleport(int x) {
    return 2 * x;
}

int n, k;
int d[100'005];
int prv[100'005];
int (*movements[])(int) = {move_forward, move_backward, teleport};

int main() {
    fastio(nullptr, false);

    memset(d, -1, sizeof(d));
    memset(prv, -1, sizeof(prv));

    cin >> n >> k;
    
    qi q;
    d[n] = 0;
    q.push(n);
    while(sz(q)) {
        auto cx = q.front(); q.pop();
        for(int i = 0; i < 3; i++) {
            int nx = movements[i](cx);
            if(nx < 0 || nx > 100'000) {
                continue;
            }
            if(d[nx] == -1) {
                q.push(nx);
                d[nx] = d[cx] + 1;
                prv[nx] = cx;
            }
        }
    }

    int cur = k;
    vi path;
    while(cur != -1) {
        path.pb(cur);
        cur = prv[cur];
    }
    reverse(all(path));

    cout << d[k] << nl;
    for(auto x : path) {
        cout << x << ' ';
    }
}