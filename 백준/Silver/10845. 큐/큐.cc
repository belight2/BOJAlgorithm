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

int main() {
    fastio(nullptr, false);

    int N{};
    cin >> N;

    deque<int> q{};
    while(N--) {
        string cmd{};
        cin >> cmd;
        if(cmd == "push") {
            int x{};
            cin >> x;
            q.pb(x);
        } else if(cmd == "pop") {
            if(sz(q)) {
                cout << q.front() << nl;
                q.pop_front();
            } else {
                cout << -1 << nl;
            }
        } else if (cmd == "size") {
            cout << sz(q) << nl;
        } else if(cmd == "empty") {
            cout << q.empty() << nl;
        } else if(cmd == "front") {
            cout << (sz(q) ? q.front() : -1) << nl;
        } else if(cmd == "back") {
            cout << (sz(q) ? q.back() : -1) << nl;
        }
    }
}