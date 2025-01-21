#include <bits/stdc++.h>

using namespace std;

queue<int> q;
vector<int> adj[100'005];
int d[100'005];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> src, int dst) {
    for(auto edge : roads) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    memset(d, 0xff, sizeof(d));
    
    d[dst] = 0;
    q.push(dst);
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]) {
            if(d[nxt] == -1 || d[nxt] > d[cur] + 1) {
                d[nxt] = d[cur] + 1;
                q.push(nxt);
            }
        }
    }
    
    vector<int> ans;
    for(auto x : src) {
        ans.push_back(d[x]);
    }
    
    return ans;
}