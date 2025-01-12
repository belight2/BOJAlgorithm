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

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m, sx, sy, ex, ey;
string board[55];
int d[55][55];

qpi q;

int main() {
    fastio(nullptr, false);

    memset(d, -1, sizeof(d));

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'D') {
                ex = i;
                ey = j;
            }
            else if(board[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            else if(board[i][j] == '*') {
                d[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    d[sx][sy] = 0;
    q.push({sx, sy});
    while(sz(q)) {
        auto [cx, cy] = q.front(); q.pop();
        char status = board[cx][cy];
        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '*' || board[nx][ny] == 'X') continue;
            if(status == '*' && board[nx][ny] != 'D' && (d[nx][ny] == -1 || d[nx][ny] > d[cx][cy] + 1)) {
                board[nx][ny] = status;
                d[nx][ny] = d[cx][cy] + 1;
                q.push({nx, ny});
            }
            else if(status == 'S' && (d[nx][ny] == -1 || d[nx][ny] > d[cx][cy] + 1)) {
                board[nx][ny] = status;
                d[nx][ny] = d[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << (d[ex][ey] == -1 ? "KAKTUS" : to_string(d[ex][ey]));
}