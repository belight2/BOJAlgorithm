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

const int INF = 0x7fffffff;

int n, m;
vti edges;
vi p;

int find(int x) {
    return (p[x] < 0 ? x : p[x] = find(p[x]));
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) {
        return 0;
    }

    if(--p[x] > p[y]) {
        swap(x, y);
    }

    p[y] = x;

    return 1;
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;

    vti(m).swap(edges);
    vi(n+1, -1).swap(p);

    for(auto &[w, u, v] : edges) {
        cin >> u >> v >> w;
    }

    sort(all(edges));

    int ans{}, cnt{};
    for(auto &[w, u, v] : edges) {
        if(cnt == n - 1) {
            break;
        }

        if(merge(u, v)) {
            ans += w;
            cnt++;
        }
    }

    cout << ans;
}