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

ull x, k;

int main() {
    fastio(nullptr, false);
    cin >> x >> k;

    vb chk(64, 1);
    for(int i = 0; i < 64; i++) {
        if((x >> i) & 1) {
            chk[i] = 0;
        }
    }

    ull y = 0;
    int kidx{}, yidx{};
    while(kidx < 64 && yidx < 64) {
        if(!chk[yidx]) {
            yidx++;
            continue;
        }
        ull bit = (k >> kidx) & 1;
        y |= (bit << yidx);
        kidx++; yidx++;
    }

    cout << y;
}