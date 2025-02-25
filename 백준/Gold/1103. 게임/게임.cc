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

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int n, m;

vs board;
vector<vi> d;
vector<vb> vis;

int dfs(int cx, int cy) {
    if(cx < 0 || cx >= n || cy < 0 || cy >= m || board[cx][cy] == 'H') {
        return 0;
    }

    if(vis[cx][cy]) {
        cout << -1;
        exit(0);
    }

    if(d[cx][cy] != -1) {
        return d[cx][cy];
    }  

    vis[cx][cy] = 1;
    int cur = board[cx][cy] - '0';
    for(int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir] * cur;
        int ny = cy + dy[dir] * cur;
        d[cx][cy] = max(d[cx][cy], dfs(nx, ny) + 1);
    }
    vis[cx][cy] = 0;
    return d[cx][cy];
}

int main() {
    fastio(nullptr, false);
    
    cin >> n >> m;

    vs(n).swap(board);
    vector<vi>(n, vi(m, -1)).swap(d);
    vector<vb>(n, vb(m)).swap(vis);

    for(auto &x : board) {
        cin >> x;
    }
    cout << dfs(0, 0);
}