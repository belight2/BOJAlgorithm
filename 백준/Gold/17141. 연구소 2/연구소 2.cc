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

int n, m;
int board[55][55];

qpi q;
int countOfBlank;
int d[55][55];

vpi virus;
int ans{INF};
bool chk[15];

int bfs() {
    int cnt{}, mx{};
    memset(d, -1, sizeof(d));
    for(int i = 0; i < sz(virus); i++) {
        if(chk[i]) {
            d[virus[i].X][virus[i].Y] = 0;
            q.push(virus[i]);
        }
    }

    cnt = sz(q);

    while(sz(q)) {
        auto [cx, cy] = q.front(); q.pop();
        
        mx = max(mx, d[cx][cy]);

        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] & 1 || (d[nx][ny] != -1 && d[nx][ny] <= d[cx][cy] + 1)) continue;
            cnt++;
            d[nx][ny] = d[cx][cy] + 1;
            q.push({nx, ny});
        }
    }

    return (cnt == countOfBlank ? mx : INF);
}

void select(int cur, int k) {
    if(k == m) {
        ans = min(ans, bfs());
        return;
    }

    for(int i = cur; i < sz(virus); i++) {
        if(chk[i]) continue;
        chk[i] = 1;
        select(i, k + 1); 
        chk[i] = 0;
    }
}

int main() {
    fastio(nullptr, false);

    memset(d, -1, sizeof(d));

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(!(board[i][j] & 1)) countOfBlank++;
            if(board[i][j] == 2) {
                virus.pb({i, j});
            }
        }
    }

    select(0, 0);

    cout << (ans == INF ? -1 : ans);
}