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
int party[1005][1005];
int d[1005][1005];

int solve(int cx, int cy) {
    if(cx == cy) {
        return 0;
    }

    if(d[cx][cy] != -1) {
        return d[cx][cy];
    }

    d[cx][cy] = 0;
    for(int md = cx; md < cy; md++) {
        d[cx][cy] = max(d[cx][cy], party[cx][md] + party[md + 1][cy]);
        d[cx][cy] = max(d[cx][cy], solve(cx, md) + solve(md + 1, cy));
    }
    return d[cx][cy];
}

int main() {
    fastio(nullptr, false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int score;
        cin >> score;
        students.pb(score);        
    }    

    for(int i = 0; i < n; i++) {
        int mn{students[i]}, mx{students[i]};
        for(int j = i + 1; j < n; j++) {
            mn = min(mn, students[j]);
            mx = max(mx, students[j]);
            party[i][j] = max(party[i][j], mx - mn);    
        }
    }  

    memset(d, -1, sizeof(d));

    cout << solve(0, n-1);
}