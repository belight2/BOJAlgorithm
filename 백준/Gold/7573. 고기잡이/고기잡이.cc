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

int n, k, m;
vpi fish;

bool fishing_success(int sx, int sy, int fx, int fy, int ex, int ey) {
    return sx <= fx && fx <= ex && sy <= fy && fy <= ey;   
}

int main() {
    fastio(nullptr, false);

    cin >> n >> k >> m;
    while(m--) {
        int x, y;
        cin >> x >> y;
        fish.pb({x, y});
    }

    sort(all(fish));

    int limit = (k - 2) / 2;
    int mx{};
    for(int i = 0; i < sz(fish); i++) {
        for(int j = 0; j < sz(fish); j++) {
            int cx = fish[i].X;
            int cy = fish[j].Y;
            for(int w = limit, h = 1; w >= 1; w--, h++) {
                int cnt{};
                for(auto [fx, fy] : fish) {
                    if(fishing_success(cx, cy, fx, fy, cx + w, cy + h)) {
                        cnt++;
                    }
                }
                mx = max(mx, cnt);
            }
        }
    }
    cout << mx;
}