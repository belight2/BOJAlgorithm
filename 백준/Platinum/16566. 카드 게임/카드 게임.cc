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

vi card(4'000'001);
int n, m, k;

int find(int x) {
    if(x == 4'000'001) return -1;
    return (card[x] == x ? card[x]++ : card[x] = find(card[x]));
}

int main() {
    fastio(nullptr, false);

    cin >> n >> m >> k;

    iota(all(card), 1);
    
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        card[x] = x;
    }

    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        cout << find(x+1) << nl;
    }
}