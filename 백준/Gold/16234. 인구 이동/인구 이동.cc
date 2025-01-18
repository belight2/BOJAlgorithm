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

int n, l, r;
int board[55][55];
int vis[55][55];

vi info;

int flood_fill() {
    vi ().swap(info);
    memset(vis, -1, sizeof(vis));
    qpi q;

    int area{};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i][j] != -1) continue;
            int cnt{1}, tot{board[i][j]};
            q.push({i, j});
            vis[i][j] = area++;
            while(sz(q)) {
                auto [cx, cy] = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] != -1) continue;
                    int diff = abs(board[cx][cy] - board[nx][ny]);
                    if(l <= diff && diff <= r) {
                        cnt++;
                        tot += board[nx][ny];
                        vis[nx][ny] = vis[cx][cy];
                        q.push({nx, ny});
                    }
                }
            }
            info.pb(tot / cnt);
        }
    }

    return area;
}


int main() {
    fastio(nullptr, false);

    cin >> n >> l >> r;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int cnt{}, days{};
    while(cnt = flood_fill(), cnt < n * n) {
        days++;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = info[vis[i][j]];
            }
        }
    }
    
    cout << days;
}