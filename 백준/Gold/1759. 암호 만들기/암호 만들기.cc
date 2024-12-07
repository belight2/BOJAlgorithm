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
string ans;
vector<char> cand;
bool isused[16];
int x, y;

bool isVowels(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void solve(int k, int depth) {
    if(depth == n) {
        if(x >= 1 && y >= 2) cout << ans << nl;
        return;
    }

    for(int i = k; i < m; i++) {
        if(isused[i]) continue;
        int &cur = (isVowels(cand[i]) ? x : y);
        cur++;
        isused[i] = 1;
        ans.pb(cand[i]);
        solve(i, depth + 1);
        ans.pop_back();
        isused[i] = 0;
        cur--;
    }
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        char x; cin >> x;
        cand.pb(x);
    }

    sort(all(cand));

    solve(0, 0);
}