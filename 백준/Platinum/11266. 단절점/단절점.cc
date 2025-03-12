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

int n, m;

vi ans;

vi adj[10'005];
vi order(10'005), low(10'005);

int cnt{1};
void dfs(int cur, int prv) {
    order[cur] = cnt++;
    low[cur] = cnt;
    
    int child{};
    for(auto nxt : adj[cur]) {
        if(nxt == prv) {
            continue;
        }

        if(!order[nxt]) {
            child++;

            dfs(nxt, cur); 

            if((!prv && child > 1) || (prv && low[nxt] >= order[cur])) {
                ans.push_back(cur);
            }

            low[cur] = min(low[cur], low[nxt]);
        }
        else {
            low[cur] = min(low[cur], order[nxt]);
        }
    }
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(register int i = 1; i <= n; i++) {
        if(!order[i]) {
            dfs(i, 0);
        }
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << sz(ans) << nl;
    for(auto v : ans) {
        cout << v << ' ';
    }
}