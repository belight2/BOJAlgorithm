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
vs board;

bool solve(int count) {
    set<string> chk;
    for(int j = 0; j < m; j++) {
        string str{};
        for(int i = count; i < n; i++) {
            str.pb(board[i][j]);
        }
        chk.insert(str);
    }

    return sz(chk) == m;
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    vs(n).swap(board);
    for(auto &str : board) {
        cin >> str;
    }

    int st{0}, en{n};
    while(st + 1 < en) {
        int mid = (st + en) >> 1;
        (solve(mid) ? st : en) = mid;
    }

    cout << st;
}