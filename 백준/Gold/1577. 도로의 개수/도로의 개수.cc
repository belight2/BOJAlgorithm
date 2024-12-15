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

const int dx[2] = { 1, 0 };
const int dy[2] = { 0, 1 };

int n, m, k;
vs cons;
ll d[105][105];

string getRoad(int sx, int sy, int ex, int ey) {
    string ret{};
    ret.pb(sx + '0');
    ret.pb(sy + '0');
    ret.pb(ex + '0');
    ret.pb(ey + '0');
    return ret;
}

ll dfs(int cx, int cy) {
    if(cx == n && cy == m) {
        return 1;
    }
    if(d[cx][cy] != -1) {
        return d[cx][cy];
    }

    d[cx][cy] = 0;

    for(int dir = 0; dir < 2; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
        if(find(all(cons), getRoad(cx, cy, nx, ny)) != cons.end()) continue;
        d[cx][cy] += dfs(nx, ny);
    }  

    return d[cx][cy];
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m >> k;

    while(k--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        cons.pb(getRoad(sx, sy, ex, ey));
        cons.pb(getRoad(ex, ey, sx, sy));       
    }    
 
    memset(d, -1, sizeof(d));

    cout << dfs(0, 0);
}