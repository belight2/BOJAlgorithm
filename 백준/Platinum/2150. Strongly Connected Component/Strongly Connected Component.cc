#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n, m, cnt, k;

int s[10'005], scc_num[10'005];
bool finished[10'005];

vi adj[10'005];
vector<vi> scc;
stack<int> stk;


int dfs(int cur) {
    s[cur] = ++cnt;
    stk.push(cur);

    int res = s[cur];
    for(int nxt : adj[cur]) {
        if(!s[nxt]) res = min(res, dfs(nxt));
        else if(!finished[nxt]) res = min(res, s[nxt]);
    }

    if(res != s[cur]) return res;

    int t{};
    vector<int> curscc;
    while(!stk.empty() && stk.top() != cur) {
        curscc.push_back(stk.top());
        stk.pop();
        finished[curscc.back()] = 1;
        scc_num[curscc.back()] = k;
    }
    
    curscc.push_back(stk.top());
    stk.pop();
    finished[curscc.back()] = 1;
    scc_num[curscc.back()] = k;

    sort(curscc.begin(), curscc.end());
    scc.push_back(curscc);
    k++;

    return res;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i++) {
        if(s[i]) continue;
        dfs(i);
    }

    sort(scc.begin(), scc.end());

    cout << k << '\n';
    for(auto &cur : scc) {
        for(auto &x : cur) {
            cout << x << ' ';
        }
        cout << -1 << '\n';
    }
}