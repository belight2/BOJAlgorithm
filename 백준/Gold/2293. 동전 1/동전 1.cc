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

int n, k;
int coin[105];
int d[2][10'005];

int main() {
    fastio(nullptr, false);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    d[0][0] = d[1][0] = 1;
    for(int i = coin[0]; i <= k; i++) {
        d[0][i] = d[0][i - coin[0]];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            d[1][j] = d[0][j] + (j - coin[i] >= 0 ? d[1][j - coin[i]] : 0);
        }
        memcpy(d[0], d[1], sizeof(d[0]));
    }

    cout << d[0][k];
}