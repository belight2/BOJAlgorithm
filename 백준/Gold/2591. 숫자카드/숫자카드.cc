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

string n;
ll d[44];

ll solve(int cur) {
    if(cur == sz(n)) {
        return d[cur] = 1;
    }

    if(n[cur] == '0') {
        return d[cur] = 0;
    }

    if(d[cur] != -1) {
        return d[cur];
    }    

    d[cur] = solve(cur + 1);
    
    int num = (n[cur] - '0') * 10;
    if(cur + 1 < sz(n) && (num += n[cur + 1] - '0') <= 34) {
        d[cur] += solve(cur + 2);
    } 

    return d[cur];
}

int main() {
    fastio(nullptr, false);

    cin >> n;

    memset(d, -1, sizeof(d));

    cout << solve(0);
}