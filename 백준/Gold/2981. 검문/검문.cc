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
vl a;

int main() {
    fastio(nullptr, false);

    cin >> n;
    vl (n).swap(a);
    for(auto &x : a) cin >> x;

    ll g = abs(a[0] - a[1]);
    for(int i = 1; i < n - 1; i++) {
        g = __gcd(g, abs(a[i] - a[i + 1]));
    }

    vl ans{g};
    for(int i = 2; i * i <= g; i++) {
        if(g % i) continue;
        ans.pb(i);
        if(i * i != g) ans.pb(g / i);
    }

    sort(all(ans));
    for(auto x : ans) cout << x << ' ';
}