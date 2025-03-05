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
vs words;

string k;

vi a;

int main() {
    fastio(nullptr, false);

    cin >> n;

    vs (n).swap(words);
    vi ('Z' - 'A' + 1, -1).swap(a);

    for(auto &str : words) {
        cin >> str;

        for(auto &x : str) {
            if(a[x - 'A'] == -1) {
                a[x - 'A'] = 0;
                k.pb(x);
            }
        }
    }

    ll ans{};
    vi mask(sz(k));
    iota(all(mask), 10 - sz(k));
    do {
        for(int i = 0; i < sz(k); i++) {
            a[k[i] - 'A'] = mask[i];
        }

        ll tot{};
        for(auto &str : words) {
            ll cur{};
            for(auto &x : str) {
                cur *= 10;
                cur += a[x - 'A'];
            }
            tot += cur;
        }

        ans = max(ans, tot);
    } while (next_permutation(all(mask)));

    cout << ans;
}