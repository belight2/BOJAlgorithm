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
vi students;
int d[1005];

int solve(int cur) {
    if(cur < 0) {
        return 0;
    }

    if(d[cur] != -1) {
        return d[cur];
    }

    int mx, mn;
    mx = mn = students[cur];
    for(int md = cur; md >= 0; md--) {
        mx = max(mx, students[md]);
        mn = min(mn, students[md]);
        d[cur] = max(d[cur], solve(md - 1) + mx - mn);
    }
    
    return d[cur];
}

int main() {
    fastio(nullptr, false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int score;
        cin >> score;
        students.pb(score);        
    }    

    memset(d, -1, sizeof(d));

    cout << solve(n - 1);
}