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

int main() {
    fastio(nullptr, false);

    cin >> n >> m;

    vs(m).swap(board);

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++) {
            board[j].pb(str[j]);
        }
    }

    for(auto &str : board) {
        reverse(all(str));
    }

    int count{};
    for( ; count < n; count++) {
        unordered_set<string> chk;
        for(auto &str : board) {
            if(chk.find(str) != chk.end()) {
                cout << count - 1; 
                exit(0);
            }
            chk.insert(str);
            str.pop_back();
        }
    }

    cout << count - 1;
}