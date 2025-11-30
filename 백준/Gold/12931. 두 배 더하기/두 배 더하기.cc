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

int dp[1005];
int prv[1005];
int solve(int x) {
    if(x <= 0) {
        return 0;
    }
    if(dp[x] != -1) {
        return dp[x];
    }
    dp[x] = solve(x - 1) + 1;
    prv[x] = 0;
    if(!(x & 1)) {
        int k = solve(x / 2) + 1;
        if(dp[x] > k) {
            dp[x] = k;
            prv[x] = 1;
        }
    }

    return dp[x];
}

bool chk(vi &x) {
    for(auto k : x) {
        if(k) {
            return 1;
        }
    }
    return 0;
}

int main() {
    fastio(nullptr, false);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 1000; i >= 0; i--) {
        if(dp[i] == -1) {
            dp[i] = solve(i);
        }
    }

    prv[1] = 0;
    prv[2] = 1;
    int N;
    cin >> N;
    vi a(N);
    for(auto &x : a) {
        cin >> x;
    }

    int ans{};
    while(chk(a)) {
        bool isdiv = 1;
        for(int &x : a) {
            if(x == 0) continue;
            isdiv &= prv[x];

            if(!prv[x]) {
                x -= 1;
                ans++;
            }
        }

        if(isdiv) {
            for(auto &x : a) {
                x /= 2;
            }
            ans++;
        }
    }

    cout << ans;
}