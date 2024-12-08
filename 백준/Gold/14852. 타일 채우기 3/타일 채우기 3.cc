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

const ll MOD = 1e9 + 7;

int n;
ll d[1'000'005];

int main() {
    fastio(nullptr, false);

    cin >> n;
    d[0] = 1;
    d[1] = 2 + d[0];
    d[2] = 7 + d[1];
    for(int i = 3; i <= n; i++) { 
        d[i] = (d[i - 1] * 2 + (d[i - 2] - d[i - 3])) % MOD;
        d[i] = (d[i] + d[i-1]) % MOD;
    }

    cout << (d[n] - d[n-1] + MOD) % MOD;
}