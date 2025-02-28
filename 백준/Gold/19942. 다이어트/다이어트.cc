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

using tiii = tuple<int, int, int, int, int>;

const int INF = 0x3f3f3f3f;

int n;
int mp, mf, ms, mv;

vector<tiii> foods;
vb isused;

int ans = INF;
vi a, b;

tiii& operator+=(tiii &A, const tiii &B) {
    auto &[am, af, as, av, ac] = A;
    auto [bm, bf, bs, bv, bc] = B;
    
    am += bm; af += bf; as += bs; av += bv; ac += bc;
    
    return A;
}

int chk() {
    tiii tot{};

    for(auto x : b) {
        tot += foods[x];
    }
    auto [p, f, s, v, c] = tot;

    return c * (p >= mp && f >= mf && v >= mv && s >= ms);
}

void solve(int idx) {
    if(int mn = chk()) {
        if(ans > mn) {
            ans = mn;
            a = b;
        }

        return;
    }

    for(int i = idx; i < n; i++) {
        if(!isused[i]) {
            b.pb(i);
            isused[i] = 1;
            solve(i);
            isused[i] = 0;   
            b.pop_back();
        }
        
    }
}
int main() {
    fastio(nullptr, false);

    cin >> n >> mp >> mf >> ms >> mv;

    vector<tiii>(n).swap(foods);
    vb(n).swap(isused);

    for(auto &[p, f, s, v, c] : foods) {
        cin >> p >> f >> s >> v >> c;
    }

    solve(0);

    cout << (ans == INF ? -1 : ans) << nl;
    for(auto x : a) {
        cout << x + 1 << ' ';
    }
}