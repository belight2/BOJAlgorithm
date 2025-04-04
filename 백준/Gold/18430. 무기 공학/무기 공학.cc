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

int n, m, ans;
vti pos;

int wood[10][10];
bool isused[10][10];

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

void func(int k, int mx) {
    ans = max(ans, mx);
    
    if(k == sz(pos)) {
        return;
    }

    for(int i = k; i < sz(pos); i++) {
        auto &[val, cx, cy] = pos[i];
        
        if(isused[cx][cy]) {
            continue; 
        }

        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            int px = cx + dx[(dir + 1) % 4];
            int py = cy + dy[(dir + 1) % 4];
            if(OOB(nx, ny) || OOB(px, py) || isused[nx][ny] || isused[px][py]) continue;
            isused[cx][cy] = isused[nx][ny] = isused[px][py] = 1;
            func(i, mx + val * 2 + wood[nx][ny] + wood[px][py]);
            isused[cx][cy] = isused[nx][ny] = isused[px][py] = 0;
        }
    }
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> wood[i][j];
            pos.pb({wood[i][j], i, j});
        }
    }

    if(n == 1 || m == 1) {
        cout << 0;
        return 0;
    }

    func(0, 0);

    cout << ans;
}