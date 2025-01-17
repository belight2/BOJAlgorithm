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

// startTime: 15:16
// submissionTime: 16:06 (67% WA)
// cause: N번 컴퓨터를 연결 못하는 경우 출력을 제외함
// submissionTime: 16:12 (67% WA)
// submissionTime: 16:13
// cuase: 1번 컴퓨터에서 N번 컴퓨터를 연결하는데 K번 이하의 케이블로 연결이 가능한 경우 0을 출력하게 해야된다.
// submissionTime: 16:37

int n, p, k;
vpi adj[1'005];
int d[1'005];
priority_queue<pi, vpi, greater<pi>> pq;

bool dijkstra(int cost) {
    memset(d, 0x3f, sizeof(d));

    d[1] = 0;
    pq.push({0, 1});
    while(sz(pq)) {
        auto [cw, cx] = pq.top(); pq.pop();
        if(d[cx] != cw) continue;
        for(auto [nw, nx] : adj[cx]) {
            if(d[nx] > d[cx] + (nw > cost)) {
                d[nx] = d[cx] + (nw > cost);
                pq.push({d[nx], nx});
            }
        }
    }

    return d[n] <= k;
}

int main() {
    fastio(nullptr, false);

    cin >> n >> p >> k;
    while(p--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }

    int st{-1}, en = 1'000'001;
    while(st + 1< en) {
        int mid = (st + en) >> 1;
        (dijkstra(mid) ? en : st) = mid;
    }

    cout << (en == 1'000'001 ? -1 : en);
}