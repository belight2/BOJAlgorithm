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

const int INF = 1e9 + 7;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
string board[55];
int sx, sy, ex, ey;

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    vector<vb> exists_nearby(n, vb(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'g') {
                for(int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                        exists_nearby[nx][ny] = 1;
                    }
                }   
            }
            else if(board[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            else if(board[i][j] == 'F') {
                ex = i;
                ey = j;
            }            
        }
    }

    using tii = tuple<pi, int, int>;
    vector<vpi> d(n, vpi(m, {INF, INF}));
    priority_queue<tii, vector<tii>, greater<tii>> pq;

    pq.push({d[sx][sy] = {0, 0}, sx, sy});
    while(sz(pq)) {
        auto [cur, cx, cy] = pq.top(); pq.pop();
        if(cur != d[cx][cy]) continue;  
        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                pi nxt = cur;
                if(board[nx][ny] == 'g') {
                    nxt.X++;
                }
                else if(board[nx][ny] == '.' && exists_nearby[nx][ny]) {
                    nxt.Y++;
                }
                if(d[nx][ny] > nxt) {
                    pq.push({d[nx][ny] = nxt, nx, ny});
                }
            }
        }
    }    

    cout << d[ex][ey].X << ' ' << d[ex][ey].Y;    
}