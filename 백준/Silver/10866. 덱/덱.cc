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

deque<int> dq;

int main() {
    fastio(nullptr, false);
    
    int N{};
    cin >> N;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front") {
            int x{};
            cin >> x;
            dq.push_front(x);
        } else if (cmd == "push_back") {
            int x{};
            cin >> x;
            dq.pb(x);
        } else if (cmd == "pop_front") {
            if (sz(dq)) {
                int x = dq.front();
                cout << x << nl;
                dq.pop_front();
            } else {
                cout << -1 << nl;
            }
        } else if (cmd == "pop_back") {
            if (sz(dq)) {
                int x = dq.back();
                cout << x << nl;
                dq.pop_back();
            } else {
                cout << -1 << nl;
            }

        } else if (cmd == "size") {
            cout << sz(dq) << nl;
        } else if (cmd == "empty") {
            cout << dq.empty() << nl;
        } else if (cmd == "front") {
            int x = (sz(dq) ? dq.front() : -1);
            cout << x << nl;
        } else if (cmd == "back") {
            int x = (sz(dq) ? dq.back() : -1);
            cout << x << nl;
        }
    }
}