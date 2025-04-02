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
vi a(125);
int d[300'005];

int solve(int n) {
    if(n == 0) {
        return 0;
    }
    if(d[n] != -1) {
        return d[n];
    }

    d[n] = 0x3f3f3f3f;
    auto mxidx = lower_bound(all(a), n) - a.begin();
    for(int i = 1; i < mxidx + (a[mxidx] == n); i++) {
        d[n] = min(d[n], solve(n - a[i]) + 1);
    }

    return d[n];
}

int main() {
    fastio(nullptr, false);

    iota(all(a), 0);
    partial_sum(all(a), a.begin());
    partial_sum(all(a), a.begin());

    cin >> n;

    memset(d, -1, sizeof(d));
    cout << solve(n);
}