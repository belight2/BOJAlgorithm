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
vi prime, ans;
vb vis;

vi eratos(int n) {
    vis.assign(n + 1, 1);
    vis[0] = vis[1] = 0;
    for(int i = 2; i* i <= n; i++) {
        if(!vis[i]) {
            continue;
        }

        for(int j = i * i; j <= n; j += i) {
            vis[j] = 0;
        }
    }

    for(int i = 2; i <= n; i++) {
        if(vis[i]) {
            prime.pb(i);
        }
    }

    return prime;
}

bool solve(int cur, int cnt) {
    if (cnt == 3) {
        if(vis[cur]) {
            ans.pb(cur);
            return 1;
        }
        return 0;
    }

    for(int idx = 0; (prime[idx] <= cur && idx < sz(prime)); idx++) {
        ans.pb(prime[idx]);
        if(solve(cur - prime[idx], cnt + 1)) {
            return 1;
        }
        ans.pop_back();
    }

    return 0;
}

int main() {
    fastio(nullptr, false);

    cin >> n;
    prime = eratos(n);

    if(solve(n, 0)) {
        for(auto x : ans) {
            cout << x << ' ';
        }
    }
    else {
        cout << -1;
    }
}