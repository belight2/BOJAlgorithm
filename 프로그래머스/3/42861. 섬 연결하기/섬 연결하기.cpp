#include <bits/stdc++.h>

using namespace std;

vector<int> p(105, -1);

int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    if(p[x] == p[y]) p[x]--;
    if(p[x] > p[y]) swap(x, y);
    p[y] = x;
    return 1;
}

int solution(int n, vector<vector<int>> costs) {
    vector<tuple<int, int, int>> edges;
    for(auto cur : costs) {
        edges.push_back({cur[2], cur[0], cur[1]});
    }
    
    sort(edges.begin(), edges.end());
    
    int cnt{}, ans{};
    for(auto &[w, u, v] : edges) {
        if(!merge(u, v)) continue;
        cnt++;
        ans += w;
        if(cnt == n - 1) break;
    }
    
    return ans;
}