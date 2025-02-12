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
vector<vi> matrix(205, vi(205));

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> matrix[i][j];

            matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
        }
    }
    
    ll ans = -10000LL * 405L;
    for(int sx = 1; sx <= n; sx++) {
        for(int sy = 1; sy <= m; sy++) {
            for(int ex = sx; ex <= n; ex++) {
                for(int ey = sy; ey <= m; ey++) {
                    ll submatrix = matrix[ex][ey] - matrix[sx - 1][ey] - matrix[ex][sy - 1] + matrix[sx - 1][sy - 1];
                    ans = max(ans, submatrix);
                }
            }
        }
    }

    cout << ans;
}