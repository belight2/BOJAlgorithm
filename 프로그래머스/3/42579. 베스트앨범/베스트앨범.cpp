#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int offset = 0;
unordered_map<string, int> idx;

vector<int> cnt;
priority_queue<pair<int, int>> songs[105];

vector<int> solution(vector<string> g, vector<int> p) {
    for(int i = 0; i < g.size(); i++) {
        string cur = g[i];
        
        if(idx.find(cur) == idx.end()) {
            idx[cur] = offset++;
            cnt.push_back(0);
        }
        cnt[idx[cur]] += p[i];
        songs[idx[cur]].push({p[i], -i});
    }
    
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < offset; i++) {
        pq.push({cnt[i], i});
    }
    
    vector<int> ans;
    while(pq.size()) {
        auto [_, cur] = pq.top(); pq.pop();
        for(int i = 0; i < 2; i++) {
            if(songs[cur].empty()) break;
            auto [__, ansidx] = songs[cur].top(); songs[cur].pop();
            ans.push_back(-ansidx);
        }
    }
    
    return ans;
}