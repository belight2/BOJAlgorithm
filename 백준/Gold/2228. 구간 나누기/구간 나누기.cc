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

const int MN = -(1 << 25);
int n, m;
vi a;

int d[105][105];

int solve(int k, int st) {
    if(k == 0) {
        return 0;
    }

    if(st > n) {
        return MN * 10;
    }

    if(d[k][st] != MN) {
        return d[k][st];
    }

    d[k][st] = solve(k, st + 1);
    for(int en = st; en <= n; en++) {
        d[k][st] = max(d[k][st], solve(k - 1, en + 2) + a[en] - a[st - 1]);
    }

    return d[k][st];
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;

    vi (n + 1).swap(a);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    } 
    
    partial_sum(all(a), a.begin());
    fill(&d[0][0], &d[n][n], MN);

    int ans{MN};
    for(int i = 1; i <= n; i++) {
        ans = max(ans, solve(m, i));
    }

    cout << ans;
}