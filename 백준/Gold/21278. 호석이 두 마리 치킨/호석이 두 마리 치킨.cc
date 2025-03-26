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

int n, m;
int d[105][105];

int main() {
    fastio(nullptr, false);

    fill(&d[0][0], &d[101][101], INF);

    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        d[u][v] = d[v][u] = 1;
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

    int ansX{}, ansY{}, ansT{INF};
    for(int u = 1; u <= n; u++) {
        for(int v = u + 1; v <= n; v++) {
            int cnt{};
            for(int i = 1; i <= n; i++) {
                cnt += min(d[u][i], d[v][i]) << 1;
            }

            if(cnt < ansT) {
                tie(ansX, ansY, ansT) = {u, v, cnt};
            }
        }
    }
    
    cout << ansX << ' ' << ansY << ' ' << ansT;
}