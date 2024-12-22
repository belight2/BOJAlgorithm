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
string a, b;
vti dx;

unordered_map<string, int> d;

using pis = pair<int, string>;
priority_queue<pis, vector<pis>, greater<pis>> pq; 

int main() {
    fastio(nullptr, false);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.pb(x + '0');
        b.pb(x + '0');
    }
    cin >> m;
    while(m--) {
        int l, r, c;
        cin >> l >> r >> c;
        dx.pb({l, r, c});
    }

    d[a] = 0;
    pq.push({d[a], a});
    while(!pq.empty()) {
        auto [cx, cy] = pq.top(); pq.pop();
        if(d[cy] != cx) continue;
        for(auto [l, r, c] : dx) {
            string nxt = cy;
            swap(nxt[l - 1], nxt[r - 1]);
            if(d.find(nxt) == d.end() || d[nxt] > cx + c) {
                d[nxt] = cx + c;
                pq.push({d[nxt], nxt});
            } 
        }
    }

    sort(all(b));
    cout << (d.find(b) == d.end() ? -1 : d[b]);
}