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

vi p(105, -1);

int find(int x) {
    return (p[x] < 0 ? x : p[x] = find(p[x]));
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    
    if(x == y) {
        return;
    }

    if(--p[x] > p[y]) {
        swap(x, y);
    }

    p[y] = x;
}

int n, m;
int d[105][105];

int main() {
    fastio(nullptr, false);
    
    memset(d, 0x3f, sizeof(d));

    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        d[u][v] = 1;
        d[v][u] = 1;
    }

    for(int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);            
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d[i][j] != INF) {
                merge(i, j);
            }
        }
    }

    vi group;
    for(int i = 1; i <= n; i++) {
        group.pb(find(i));
    }
    sort(all(group));
    group.erase(unique(all(group)), group.end());

    vpi ans(*max_element(all(group)) + 1, {INF, n + 1});
    for(int i = 1; i <= n; i++) {
        int mx = 0;
        for(int j = 1; j <= n; j++) {
            mx = max(mx, (d[i][j] != INF) * d[i][j]);
        }
        ans[find(i)] = min(ans[find(i)], {mx, i});
    }

    vi tmp;
    for(auto x : group) {
        tmp.pb(ans[find(x)].Y);
    }

    sort(all(tmp));
    cout << sz(group) << nl;
    for(auto x : tmp) {
        cout << x << nl;
    }
}