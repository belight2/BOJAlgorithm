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

int n, m, t;
deque<int> circle[55];
bool vis[55][55];

bool OOB(int row) {
    return row < 0 || row >= n;
}

void rotate_circle(int x, int d, int k) {
    for(int idx = x; idx <= n; idx += x) {
        for(int i = 0; i < k; i++) {
            if(d) {
                circle[idx - 1].push_back(circle[idx - 1].front());
                circle[idx - 1].pop_front();
            }
            else {
                circle[idx - 1].push_front(circle[idx - 1].back());
                circle[idx - 1].pop_back();
            }
        }
    }
}

int bfs(int sx, int sy) {
    int default_num = circle[sx][sy];

    qpi q;
    int cnt{1};
    vis[sx][sy] = 1;
    q.push({sx, sy});

    while(sz(q)) {
        auto [cx, cy] = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = (cy + dy[dir] + m) % m;
            if(OOB(nx) || vis[nx][ny] || circle[nx][ny] != default_num) {
                continue;
            }
            cnt++;
            circle[nx][ny] = 0;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    if(cnt > 1) {
        circle[sx][sy] = 0;
    }

    return cnt;
}

bool delete_same_number() {
    
    memset(vis, 0, sizeof(vis));

    int mxcnt{1};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] || circle[i][j] == 0) {
                continue;
            }
            mxcnt = max(mxcnt, bfs(i, j));      
        }
    }

    return mxcnt > 1;
}

void assign_circle_by_avg() {
    int tot{}, cnt{};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!circle[i][j]) {
                continue;
            }
            cnt++;
            tot += circle[i][j];
        }
    }

    double avg = (double)tot / cnt;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!circle[i][j]){
                continue;
            } 
            if((double)circle[i][j] < avg){
                circle[i][j]++;
            } 
            else if((double)circle[i][j] > avg) {
                circle[i][j]--;
            }
        }
    }
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            circle[i].push_back(x);
        }
    }

    while(t--) {
        int x, d, k;
        cin >> x >> d >> k;
        
        rotate_circle(x, d, k);
        if(delete_same_number()) {
            continue;
        }
        assign_circle_by_avg();
    }

    int ans{};
    for(int i = 0; i < n; i++) ans += accumulate(all(circle[i]), 0);

    cout << ans;
}