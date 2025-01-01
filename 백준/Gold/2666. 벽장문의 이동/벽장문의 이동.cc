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

const int INF = 0x3f3f3f3f;

int n, m;
int sx, sy;
int a[25];
int d[25][25][25];

int solve(int cx, int cy, int idx) {
    if(idx == m) {
        return 0;
    }

    if(d[cx][cy][idx] != -1) {
        return d[cx][cy][idx];
    }

    int nx = a[idx];
    if(cx == nx || cy == nx) {
        d[cx][cy][idx] = solve(cx, cy, idx + 1);
    }
    else if(cx < nx && nx < cy) {
        d[cx][cy][idx] = min(solve(nx, cy, idx + 1) + abs(cx - nx), solve(cx, nx, idx + 1) + abs(nx - cy));
    }
    else if(nx < cx) {
        d[cx][cy][idx] = solve(nx, cy, idx + 1) + abs(cx - nx);
    }
    else if(cx < nx) {
        d[cx][cy][idx] = solve(cx, nx, idx + 1) + abs(cy - nx);
    }

    return d[cx][cy][idx];
}

int main() {
    fastio(nullptr, false);

    cin >> n >> sx >> sy >> m;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    memset(d, -1, sizeof(d));
    cout << solve(sx, sy, 0);
}