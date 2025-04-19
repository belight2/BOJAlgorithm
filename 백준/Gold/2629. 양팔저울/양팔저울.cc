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

int n, m;
vi a;

int d[31][15005];

int main() {
    fastio(nullptr, false);

    cin >> n;
    vi (n + 1).swap(a);
    d[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 0; j <= 15000 - a[i]; j++) {
            if(d[i-1][j]) {
                d[i][j + a[i]] = d[i][abs(j - a[i])] = d[i][j] = d[i - 1][j];
            }
        }
    }

    cin >> m;
    while(m--) {
        int x;
        cin >> x;
        cout << (d[n][min(15001, x)] ? "Y " : "N ");
    }
}