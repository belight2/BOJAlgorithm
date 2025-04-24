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

double x, y, c;

int main() {
    fastio(nullptr, false);

    cin >> x >> y >> c;
    
    double st{}, en{min(x, y)};
    while(en - st >= 0.001) {
        double md = (st + en) / 2;
        double h1 = sqrt(y * y - md * md);
        double h2 = sqrt(x * x - md * md);
        double cur = (h1 * h2) / (h1 + h2);

        (cur < c ? en : st) = md;
    }

    cout << fixed << setprecision(3);
    cout << st;
}