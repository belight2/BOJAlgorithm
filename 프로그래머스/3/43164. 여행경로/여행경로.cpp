#include <bits/stdc++.h>

using namespace std;

int cnt;
vector<string> ans;
vector<bool> vis(10'005);

bool dfs(string cur, vector<vector<string>> &t) {
    ans.push_back(cur);
    if(cnt == t.size()) {
        return 1;
    }
    
    for(int i = 0; i < t.size(); i++) {
        if(vis[i] || t[i][0] != cur) continue;
        vis[i] = 1;
        cnt++;
        if(dfs(t[i][1], t)) return 1;
        cnt--;
        vis[i] = 0;
    }
    
    ans.pop_back();
    return 0;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets);
    return ans;
}