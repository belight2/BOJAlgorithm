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

// 동, 서, 남, 북
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

int n, m;
bool board[105][105];

queue<ti> q; // { dir, x, y }
int d[4][105][105];

int sd, sx, sy;
int ed, ex, ey;

bool OOB(int x, int y) {
    return x < 0 or x >= n or y < 0 or y >= m;
}

pi go_k(int cx, int cy, int dir, int k) {
    return { cx + dx[dir] * k, cy + dy[dir] * k };
}

int turn(int dir, int offset) {
    return ((dir >> 1 << 1) + offset) % 4;
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    cin >> sx >> sy >> sd;
    cin >> ex >> ey >> ed;

    sd--, sx--, sy--;
    ed--, ex--, ey--;

    memset(d, -1, sizeof(d));

    d[sd][sx][sy] = 0;
    q.push({sd, sx, sy});
    while(sz(q)) {
        auto [cd, cx, cy] = q.front(); q.pop();
        // first command : Go k
        for(int k = 1; k <= 3; k++) {
            auto [nx, ny] = go_k(cx, cy, cd, k);
            if(OOB(nx, ny) || board[nx][ny]) break;
            if(d[cd][nx][ny] != -1 && d[cd][nx][ny] <= d[cd][cx][cy] + 1) continue;
            d[cd][nx][ny] = d[cd][cx][cy] + 1;
            q.push({cd, nx, ny});
        }

        // second command : turn
        for(int offset = 2; offset <= 3; offset++) {
            int nd = turn(cd, offset);
            if(d[nd][cx][cy] != -1 && d[nd][cx][cy] <= d[cd][cx][cy] + 1) continue;
            d[nd][cx][cy] = d[cd][cx][cy] + 1;
            q.push({nd, cx, cy});
        }
    }

    cout << d[ed][ex][ey];
}