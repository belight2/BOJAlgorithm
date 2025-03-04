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
vi tite, mite;

int main() {
    fastio(nullptr, false);

    cin >> n >> m;

    vi (m + 1).swap(tite);
    vi (m + 1).swap(mite);

    for(int i = 0; i < n; i++) {
        int h{};
        cin >> h;

        if(i & 1) {
            tite[m - h + 1]++;
        }
        else {
            mite[h]++;
        }
    }

    for(int i = 1; i <= m; i++) {
        tite[i] += tite[i - 1];
        mite[m - i] += mite[m - i + 1];
    }

    ll ans = 0x3f3f3f3f;
    int cnt{};
    for(int i = 1; i <= m; i++) {
        int cur = tite[i] + mite[i];
        if(cur < ans) {
            cnt = 1;
            ans = cur;
            continue;
        }
        cnt += ans == cur;
    }

    cout << ans << ' ' << cnt;
}