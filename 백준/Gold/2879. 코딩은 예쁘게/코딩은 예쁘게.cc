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

const int INF = 0x3f3f3f3f;

int n;
vi a, b;

int endidx(int st, int flag, int &mn) {
    for(int en = st + 1; en < n; en++) {
        int cur = a[en] - b[en];
        if((flag < 0 && cur < 0) || (flag > 0 && cur > 0)) {
            mn = min(mn, abs(cur));
            continue;
        }
        return en; 
    }
    return n;
}

int main() {
    fastio(nullptr, false);

    cin >> n;

    vi (n).swap(a);
    for(auto &x : a) {
        cin >> x;
    }

    vi (n).swap(b);
    for(auto &x : b) {
        cin >> x;
    }

    int cnt{};
    while(a != b) {
        int st{};
        while(st < n) {
            int flag = a[st] - b[st];
            
            if(flag == 0) {
                st++;
                continue;
            }

            int mn = abs(a[st] - b[st]);
            int en = endidx(st, flag, mn);

            cnt += mn;
            for(int i = st; i < en; i++) {
                a[i] += (flag < 0 ? +mn : -mn );
            }

            st = en;
        }
    }

    cout << cnt;
}