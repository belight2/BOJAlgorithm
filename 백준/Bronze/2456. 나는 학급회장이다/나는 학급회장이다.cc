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

int n;
vector<vi> p(3, vi(3));

int main() {
    fastio(nullptr, false);

    cin >> n;
    while(n--) {
        for(auto &x : p) {
            int t; cin >> t;
            x[t-1]++;
        }
    }

    vi sc;
    vti t;
    for(auto &x : p) {
        t.pb({x[2], x[1], x[0]});
        int tot{};
        for(int i = 1; i <= 3; i++) {
            tot += i * x[i-1];
        }
        sc.pb(tot);
    }

    int ans = -1, cnt{};
    int mx = *max_element(all(sc));
    for(int i = 0; i < 3; i++) {
        if(sc[i] != mx) continue;
        if(ans == -1 || t[ans] < t[i]) {
            ans = i;
            cnt = 1;
        }
        else if(t[ans] == t[i]) cnt++;
    }

    if(cnt == 1) {
        cout << ans+1 << ' ' << mx;
    }
    else {
        cout << 0 << ' ' << mx;
    }
}