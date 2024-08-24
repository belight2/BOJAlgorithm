#include <bits/stdc++.h>
#define sz(x) int((x).size())

using namespace std;

vector<int> adj[20005];
int dist[20005];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(auto &cur : edge){
        adj[cur[0]].push_back(cur[1]);
        adj[cur[1]].push_back(cur[0]);
    }
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    int mx = *max_element(dist, dist+n+1);
    for(int i = 1; i <= n; i++) if(dist[i] == mx) answer++;
    return answer;
}