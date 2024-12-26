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
vpi pos;

int main() {
    fastio(nullptr, false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pos.pb({x, y});
    }

    sort(all(pos));

    vi lis, seq(n);
    for(int i = 0; i < n; i++) {
        int idx = lower_bound(all(lis), pos[i].Y) - lis.begin();

        if(idx == sz(lis)) lis.pb(pos[i].Y);
        else lis[idx] = pos[i].Y;

        seq[i] = idx;
    }

    vi ans{};
    for(int i = n - 1, t = sz(lis) - 1; i >= 0; i--) {
        if(seq[i] ^ t) {
            ans.pb(pos[i].X);
            continue;
        }
        t--;
    }

    cout << sz(ans) << nl;
    for(auto it = ans.rbegin(); it < ans.rend(); it++) {
        cout << *it << nl;
    }
}