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

const int dx[]{1, 0, -1, 0};
const int dy[]{0, 1, 0, -1};

int n, m;
vector<vector<vi>> board;
vector<vb> vis;

void bfs(int sx, int sy) {
    int a = board[0][sx][sy];
    int b = board[1][sx][sy];
    qpi q;

    board[0][sx][sy] = b;
    vis[sx][sy] = 1;
    q.push({sx, sy});

    while(sz(q)) {
        auto [cx, cy] = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(!vis[nx][ny] && board[0][nx][ny] == a) {
                board[0][nx][ny] = b;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}
int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    vector<vector<vi>> (2, vector<vi>(n, vi(m))).swap(board);    
    vector<vb>(n, vb(m)).swap(vis);
    for(auto &x : board) {
        for(auto &y : x) {
            for(auto &z : y) {
                cin >> z;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[0][i][j] != board[1][i][j]) {
                bfs(i, j);
                cout << (board[0] == board[1] ? "YES" : "NO");
                exit(0);
            }
        }
    }
    
    cout << (board[0] == board[1] ? "YES" : "NO");
}