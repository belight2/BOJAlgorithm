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

const int NONE = -2;
const int dx[]{1, 0, -1, 0};
const int dy[]{0, 1, 0, -1};

int n, m;
vector<vi> board;
vector<vi> vis;

vector<vi> rotate(vector<vi> board) {
    vector<vi> rboard(n, vi(n, NONE));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n ; j++) {
            rboard[n - j - 1][i] = board[i][j];
        }
    }
    return rboard;
}

vector<vi> gravity(vector<vi> board) {
    vector<vi> gboard(n, vi(n, NONE));
    for(int j = 0; j < n; j++) {
        int idx = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(board[i][j] == -1) {
                idx = i;
            }
            if(board[i][j] != NONE) {
                gboard[idx][j] = board[i][j];
                idx--;
            }
        }
    }
    return gboard;
}

tuple<int, int, pi> bfs(int sx, int sy, bool mode) {
    qpi q;
    vector<vb> vis(n, vb(n));
    int cnt{1}, rainbow{0};
    pi cpos{sx, sy};

    vis[sx][sy] = 1;
    q.push({sx, sy});

    while(sz(q)) {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                continue;
            }

            if(!vis[nx][ny] && (board[nx][ny] == board[sx][sy] || board[nx][ny] == 0)) {
                cnt++;
                rainbow += board[nx][ny] == 0;
                if(board[nx][ny] != 0) {
                    cpos = min(cpos, {nx, ny});
                }
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    if(mode) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j]) {
                    board[i][j] = NONE;
                } 
            }
        }
    }

    return {cnt, rainbow, cpos};
}

bool chk(tuple<int, int, pi> a, tuple<int, int, pi> b) {
    if(a == b) {
        return 0;
    }

    auto &[ax, ay, az] = a;
    auto &[bx, by, bz] = b;

    if(ax == bx) {
        if(ay == by) {
            return bz > az;
        }
        return by > ay;
    }
    return bx > ax;
}

int main() {
    fastio(nullptr, false);
    
    cin >> n >> m;
    vector<vi>(n, vi(n)).swap(board);
    for(auto &row : board) {
        for(auto &col : row) {
            cin >> col;
        }
    }

    int ans{}, mx{};
    while(1){
        int ar{};
        pi pos{-1, -1};

        mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] <= 0) {
                    continue;
                }
                auto [cnt, cr, cpos] = bfs(i, j, 0);
                if(cnt > 1 && chk({mx, ar, pos}, {cnt, cr, cpos})) {
                    mx = cnt;
                    ar = cr;
                    pos = cpos;
                }
            }
        }

        if(!mx) {
            break;
        }

        ans += mx * mx;
        bfs(pos.X, pos.Y, 1);
        board = gravity(rotate(gravity(board)));
    }

    cout << ans;
}