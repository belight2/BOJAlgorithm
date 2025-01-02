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
vpl points;

int main() {
    fastio(nullptr, false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.pb({x, y});
    }
    
    ll ans{};
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                ll x = (points[i].X - points[j].X) * (points[i].X - points[j].X) + (points[i].Y - points[j].Y) * (points[i].Y - points[j].Y);
                ll y = (points[i].X - points[k].X) * (points[i].X - points[k].X) + (points[i].Y - points[k].Y) * (points[i].Y - points[k].Y);
                ll z = (points[k].X - points[j].X) * (points[k].X - points[j].X) + (points[k].Y - points[j].Y) * (points[k].Y - points[j].Y);
                if(x == y + z || y == x + z || z == x + y) {
                    ans++;
                }
            }
        }
    }
    
    cout << ans;
}