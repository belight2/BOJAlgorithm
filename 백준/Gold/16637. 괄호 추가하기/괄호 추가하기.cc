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
string formula;
vector<char> op;
vl number;

ll ans = -(1LL << 40);
int d[10];
bool isused[10];

ll calculate(ll l, char op, ll r) {
    if (op == '+') {
        return l + r;
    }
    if (op == '-') {
        return l - r;
    }
    return l * r;
}

ll cal() {
    vl new_number;
    vector<char> new_op;
    vb used(sz(number));
    for (int i = 0; i < sz(op); i++) {
        if(!d[i]) {
            if(!used[i]) {
                new_number.pb(number[i]);
            } 
            new_op.pb(op[i]);
            continue;
        }
        isused[i] = used[i + 1] = 1;
        ll cur = calculate(number[i], op[i], number[i + 1]);
        new_number.pb(cur);
    }
    if(!used[sz(number) - 1]) {
        new_number.pb(number.back());
    }

    ll ret = new_number.front();
    for(int i = 0; i < sz(new_op); i++) {
        ret = calculate(ret, new_op[i], new_number[i + 1]);
    }
    return ret;
}

void solve(int idx) {
    if (idx >= sz(op)) {
        ans = max(ans, cal());        
        return;
    }

    if (!isused[idx]) {
        // 2가지 중 하나의 일을 한다.
        // 괄호를 씌운다, 넘어간다
        isused[idx] = 1;
        solve(idx + 1);
        d[idx] = 1;
        solve(idx + 2);
        d[idx] = 0;
        isused[idx] = 0;
    }
}

int main() {
    fastio(nullptr, false);
    
    cin >> n >> formula;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            op.pb(formula[i]);
        }
        else {
            number.pb(formula[i] - '0');
        }
    }

    solve(0);

    cout << ans;
}