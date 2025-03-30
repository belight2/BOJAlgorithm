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

using psi = pair<string, int>;

string str;
vb chk;

int main() {
    fastio(nullptr, false);

    cin >> str;
    vb(sz(str)).swap(chk);    
    for(int i = 0; i < sz(str); i++) {
        vector<psi> cand{};
        for(int j = 0; j < sz(str); j++) {
            if(!chk[j]) {
                string cur{};
                chk[j] = 1;
                for(int k = 0; k < sz(str); k++) {
                    if(chk[k]) {
                        cur.pb(str[k]);
                    }
                }
                chk[j] = 0;
                cand.pb({cur, j});
            }
        }
        sort(all(cand));
        chk[cand.front().Y] = 1;
        cout << cand.front().X << nl;
    }
}