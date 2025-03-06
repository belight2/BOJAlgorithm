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

vi eratos(5'000'001);

void cal_eratos(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(eratos[i] == i) {
            for(int j = i * i; j <= n; j += i) {
                eratos[j] = i;
            }
        }
    }
}

int n, k;

int main() {
    fastio(nullptr, false);

    iota(all(eratos), 0);
    cal_eratos(5'000'000);
    
    cin >> n;

    while(n--) {
        cin >> k;

        vi ans;
        while(k > 1) {
            ans.pb(eratos[k]);
            k /= eratos[k];
        }
        
        sort(all(ans));

        for(auto &x : ans) {
            cout << x << ' ';
        }
        cout << nl;
    }
}