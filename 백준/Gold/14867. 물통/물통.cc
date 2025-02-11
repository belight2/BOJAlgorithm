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

ll a, b, c, d;
map<pl, int> vis;

pl oper(ll x, ll y, int dir) {
    if(dir == 0) {
        return {a, y};
    }
    if(dir == 1) {
        return {x, b};
    }
    if(dir == 2) {
        return {0, y};
    }
    if(dir == 3) {
        return {x, 0};
    }
    if(dir == 4) {
        y += x;
        ll remain = y - min(b, y);
        return {remain, y - remain};
    }
    if(dir == 5) {
        x += y;
        ll remain = x - min(a, x);
        return {x - remain, remain};
    }
}

void bfs(int sx, int sy) {
    qpl q;
    vis[make_pair(sx, sy)] = 0;
    q.push({sx, sy});

    while(sz(q)) {
        auto [cx, cy] = q.front(); q.pop();
        pl cur = make_pair(cx, cy);
        for(int dir = 0; dir < 6; dir++) {
            auto [nx, ny] = oper(cx, cy, dir);
            pl nxt = make_pair(nx, ny);
            if(vis.find(nxt) == vis.end() || vis[nxt] > vis[cur] + 1) {
                vis[nxt] = vis[cur] + 1;
                q.push({nx, ny});
            }
        }        
    }
}

int main() {
    fastio(nullptr, false);

    cin >> a >> b >> c >> d;

    bfs(0, 0);

    pl idx = make_pair(c, d);
    cout << (vis.find(idx) == vis.end() ? -1 : vis[idx]);
}