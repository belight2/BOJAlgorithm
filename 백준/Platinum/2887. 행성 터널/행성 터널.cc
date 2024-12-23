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

vi p(100'005, -1);

int find(int x) { return (p[x] < 0 ? x : p[x] = find(p[x])); }

int merge(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return 0;

    if(p[x] == p[y]) p[x]--;
    if(p[x] > p[y]) swap(x, y);
    p[y] = x;
    return 1;
}

int n;
vpl xpos, ypos, zpos;

int main() {
    fastio(nullptr, false);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        xpos.pb({x, i});
        ypos.pb({y, i});
        zpos.pb({z, i});
    }

    sort(all(xpos));
    sort(all(ypos));
    sort(all(zpos));

    vtl edges;
    for(int i = 0; i < n - 1; i++) {
        edges.pb({abs(xpos[i].X - xpos[i+1].X), xpos[i].Y, xpos[i+1].Y});
        edges.pb({abs(ypos[i].X - ypos[i+1].X), ypos[i].Y, ypos[i+1].Y});
        edges.pb({abs(zpos[i].X - zpos[i+1].X), zpos[i].Y, zpos[i+1].Y});
    }

    sort(all(edges));
    
    int cnt{};
    ll ans{};
    for(auto &[cost, x, y] : edges) {
        if(!merge(x, y)) continue;
        cnt++;
        ans += cost;
        if(cnt == n - 1) break;
    }

    cout << ans;
}