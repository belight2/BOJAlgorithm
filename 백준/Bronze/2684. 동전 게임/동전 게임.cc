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

const string seq[8] = {
    "TTT",
    "TTH",
    "THT",
    "THH",
    "HTT",
    "HTH",
    "HHT",
    "HHH"
};

void init(unordered_map<string, int> &m) {
    for(int i = 0; i < 8; i++) {
        m[seq[i]] = 0;
    }
}

void solve(int tc) {
    unordered_map<string, int> um;
    init(um);

    string line;
    cin >> line;

    deque<char> dq;
    for(char x : line) {
        dq.push_back(x);
        if(sz(dq) != 3) continue;
        um[string(all(dq))]++;
        dq.pop_front();
    }

    for(int i = 0; i < 8; i++) {
        cout << um[seq[i]] << ' ';
    }
    cout << nl;
}

int main() {
    fastio(nullptr, false);
    int tc{};
    cin >> tc;
    for(int i = 1; i <= tc; i++) solve(i);
}