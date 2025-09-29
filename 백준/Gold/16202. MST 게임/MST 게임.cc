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

int p[1005];
int n, m, k;
vti edges;

int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    
    if(x == y) {
        return 0;
    }

    if(p[x] == p[y]) {
        p[x]--;
    }

    if(p[x] > p[y]) {
        swap(x, y);
    }

    p[y] = x;
    return 1;
}

int st{};
int cal_mst() {
    memset(p, 0xff, sizeof(p));
    
    int sc{}, cnt{};
    for(int i = st; i < sz(edges); i++) {
        auto [u, v, w] = edges[i];
        if(merge(u, v)) {
            sc += w;
            cnt++;
        }

        if(cnt == n - 1) {
            st++;
            return sc;
        }
    }
    st++;
    return 0;
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m >> k;
    
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges.pb({u, v, i});
    }
    
    int sc;
    while(sc = cal_mst(), k--) {
        cout << sc << ' ';
    }
}