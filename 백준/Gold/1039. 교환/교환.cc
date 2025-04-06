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

queue<string> q;
int n, k;

int main() {
    fastio(nullptr, false);

    cin >> n >> k;

    q.push(to_string(n));
    while(k--) {
        int s = sz(q);
        unordered_set<string> vis;
        
        while(s--) {
            auto cur = q.front(); q.pop();
            
            for(int i = 0; i < sz(cur); i++) {
                for(int j = i + 1; j < sz(cur); j++) {
                    if(i == 0 && cur[j] == '0') {
                        continue;
                    }
                    
                    swap(cur[i], cur[j]);
                    if(vis.find(cur) == vis.end()) {
                        vis.insert(cur);
                        q.push(cur);
                    }
                    swap(cur[i], cur[j]);
                }
            }
        }
    }

    int ans{-1};
    while(sz(q)) {
        auto cur = q.front(); q.pop();
        ans = max(ans, stoi(cur));
    }

    cout << ans;
}