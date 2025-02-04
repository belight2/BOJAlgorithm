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

string src;

vi construct_fail_function(const string &dst) {
    vi fail(sz(dst));
    int j{};
    for(int i = 1; i < sz(dst); i++) {
        while(j > 0 && dst[i] != dst[j]) j = fail[j - 1];
        if(dst[i] == dst[j]) fail[i] = ++j;
    }
    return fail;
}


int main() {
    fastio(nullptr, false);

    cin >> src;

    int ans{0};
    for(int i = 0; i < sz(src); i++) {
        string cur = src.substr(i, sz(src));

        vi a = construct_fail_function(cur);

        ans = max(ans, *max_element(all(a)));
    }       

    cout << ans;
}