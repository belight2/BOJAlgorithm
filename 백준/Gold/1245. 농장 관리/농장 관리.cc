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

const int dx[]{1, 1, 1, 0, 0, -1, -1, -1};
const int dy[]{1, 0, -1, 1, -1, 1, 0, -1};

int n, m;
vector<vi> board;
vector<vb> vis;

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

bool bfs(int sx, int sy) {
    bool peak{1};

    qpi q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while(sz(q)) {
        auto [cx, cy] = q.front(); q.pop();
        for(int dir = 0; dir < 8; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(OOB(nx, ny)) continue;
            peak &= board[nx][ny] <= board[sx][sy];
            if(!vis[nx][ny] && board[nx][ny] && board[nx][ny] == board[sx][sy]) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    
    return peak;
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    
    vector<vi> (n, vi(m)).swap(board);
    vector<vb> (n, vb(m)).swap(vis);
    for(auto &row : board) {
        for(auto &col : row) {
            cin >> col;
        }
    }

    int ans{};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && board[i][j]) {
                ans += bfs(i, j);
            } 
        }
    }

    cout << ans;
}