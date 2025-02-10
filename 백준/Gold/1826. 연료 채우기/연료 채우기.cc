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
int village, cur;
priority_queue<int> pq;
vpi pos;

int main() {
    fastio(nullptr, false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pos.pb({x, y});
    }
    cin >> village >> cur;

    sort(all(pos));

    int idx{}, ans{};

    while(cur < village) {
        while(idx < n && cur >= pos[idx].X) {
            pq.push(pos[idx++].Y);
        }

        if(!sz(pq)) {
            break;
        }

        cur += pq.top();
        pq.pop();
        ans++;
    }

    cout << (cur >= village ? ans : -1);
}