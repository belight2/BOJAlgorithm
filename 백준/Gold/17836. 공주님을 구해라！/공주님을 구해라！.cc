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
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m, t;
int board[105][105];
int d[2][105][105];

pi sword_pos = { -1, -1 };

int ans = INF;

void bfs(int sx, int sy, int status, int s_dist, int (*d)[105]) {
    qpi q;
    d[sx][sy] = s_dist;
    q.push({sx, sy});

    while(sz(q)) {
        auto [cx, cy] = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(status ? (d[nx][ny] == INF || d[nx][ny] > d[cx][cy] + 1) 
                : (board[nx][ny] != 1 && (d[nx][ny] == INF || d[nx][ny] > d[cx][cy] + 1))
            ) 
            {
                d[nx][ny] = d[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    ans = min(ans, d[n - 1][m - 1]);
}

int main() {
    fastio(nullptr, false);

    memset(d, 0x3f, sizeof(d));

    cin >> n >> m >> t;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];

            if(board[i][j] == 2) {
                sword_pos = {i, j};
                board[i][j] = 0;
            }
        }
    }

    bfs(0, 0, 0, 0, d[0]);

    auto [sx, sy] = sword_pos;
    if(sx != -1 && d[0][sx][sy] != -1){
        bfs(sx, sy, 1, d[0][sx][sy], d[1]);
    }
    
    cout << ((ans == INF || ans > t) ? "Fail" : to_string(ans));
}