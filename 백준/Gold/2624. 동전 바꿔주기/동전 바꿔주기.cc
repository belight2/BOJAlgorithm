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

// startTime: 20:23


int t, k;

int coin[105];
int cnt[105];

int d[10'005][105];

int dp(int cur, int idx) {
    if(cur <= 0 || idx >= k) {
        return cur == 0;
    }

    if(d[cur][idx] != -1) {
        return d[cur][idx];
    }

    d[cur][idx] = 0;
    for(int i = 0; i <= cnt[idx]; i++) {
        d[cur][idx] += dp(cur - coin[idx] * i, idx + 1);    
    }

    return d[cur][idx];
}

int main() {
    fastio(nullptr, false);

    cin >> t >> k;
    for(int i = 0; i < k; i++) {
        cin >> coin[i] >> cnt[i];
    }

    memset(d, -1, sizeof(d));
    cout << dp(t, 0) << nl;
}