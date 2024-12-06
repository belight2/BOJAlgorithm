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

int n, m, k;
string board[105];
int d[105][105][85];

string str;

int solve(int x, int y, int idx) {
    if(idx + 1 == sz(str)) {
        return 1;
    }

    if(d[x][y][idx] != -1) {
        return d[x][y][idx];
    }

    char nxt = str[idx + 1];
    d[x][y][idx] = 0;
    for(int jump = 1; jump <= k; jump++) {
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir] * jump;
            int ny = y + dy[dir] * jump;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != nxt) continue;
            d[x][y][idx] += solve(nx, ny, idx + 1);
        }
    }

    return d[x][y][idx];
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> board[i];
    cin >> str;

    int ans{};
    memset(d, -1, sizeof(d));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == str[0]) {
                ans += solve(i, j, 0);
            }
        }
    }

    cout << ans;
}