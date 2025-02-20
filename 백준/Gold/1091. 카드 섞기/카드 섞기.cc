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
int p[50], s[50];

int d[2][50];

bool is_same_value(int k) {
    bool ret{1};
    for(int i = 0; i < n; i++) {
        ret &= d[k][i] == i;
    }
    return ret;
}

void move_value(int dst, int src) {
    for(int i = 0; i < n; i++) {
        d[dst][s[i]] = d[src][i]; 
    }
}

bool solve_it(int k) {
    bool ret{1};
    for(int i = 0; i < n; i++) {
       ret &= p[d[k][i]] == (i % 3);
    }
    return ret;
}

int main() {
    fastio(nullptr, false);

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    int ans{0};
    iota(d[0], d[0] + n, 0);
    while(!solve_it(ans % 2)) {
        ans++;
        move_value(ans % 2, (ans - 1) % 2);
        if(is_same_value(ans % 2)) {
            ans = -1;
            break;
        }
    }

    cout << ans;
}