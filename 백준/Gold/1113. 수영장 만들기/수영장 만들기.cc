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

const int dx[] = {0, 0, 0, 0, 1, -1};
const int dy[] = {1, 0, -1, 0, 0, 0};
const int dz[] = {0, -1, 0, 1, 0, 0};

int n, m;
bool board[10][55][55];

int bfs(int sx, int sy, int sz, bool mode) {
    qti q;
    board[sx][sy][sz] = 1;
    q.push({sx, sy, sz});
    int mxdir = mode ? 5 : 6;
    int cnt{1};
    while(sz(q)) {
        auto [cx, cy, cz] = q.front(); q.pop();
        
        for(int dir = 0; dir < mxdir; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            int nz = cz + dz[dir];  
            if(nx < 0 || nx >= 10 || ny < 0 || ny >= n + 2 || nz < 0 || nz >= m + 2) {
                continue;
            }
            if(!board[nx][ny][nz]) {
                cnt++;
                board[nx][ny][nz] = 1;
                q.push({nx, ny, nz});
            }
        }
    }

    return cnt;
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string line;
        cin >> line;
        for(int j = 1; j <= m; j++) {
            int cnt = line[j - 1] - '0';
            for(int k = 1; k <= cnt; k++) {
                board[k][i][j] = 1;
            }
        }
    }

    bfs(0, 0, 0, 1);

    int ans{};
    for(int k = 0; k < 10; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(!board[k][i][j]) {
                    ans += bfs(k, i, j, 0);
                }
            }
        }
    }
    
    cout << ans;
}