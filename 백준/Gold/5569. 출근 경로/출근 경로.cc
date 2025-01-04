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

const int MOD = 100'000;
const int dx[2] = { 1, 0 };
const int dy[2] = { 0, 1 };

int n, m;
int d[105][105][2][2];

int solve(int cx, int cy, int dir, int curvable) {
    if(cx == n && cy == m) {
        return 1;
    }

    if(d[cx][cy][dir][curvable] != -1) {
        return d[cx][cy][dir][curvable];
    }

    d[cx][cy][dir][curvable] = 0;

    // 방향을 바꾸지 않는다.  
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];

    // 범위 내일 때.
    if(nx <= n && ny <= m) {
        // curvable이 0이었던 상태인 경우 curvable을 1로 바꾼다.
        d[cx][cy][dir][curvable] = solve(nx, ny, dir, curvable | 1);
    }    

    // curvable이 1이었을 때, 방향을 바꿔본다.
    if(curvable) {
        int nx = cx + dx[!dir];
        int ny = cy + dy[!dir];
        if(nx <= n && ny <= m) {
            d[cx][cy][dir][curvable] += solve(nx, ny, !dir, curvable & 0);
        }
    }

    return d[cx][cy][dir][curvable] %= MOD;
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    memset(d, -1, sizeof(d));

    cout << (solve(1, 2, 1, 1) + solve(2, 1, 0, 1)) % MOD;
}