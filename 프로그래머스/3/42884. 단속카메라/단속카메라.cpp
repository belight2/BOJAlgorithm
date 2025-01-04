#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
#define X first
#define Y second

vector<pi> lines;

int solution(vector<vector<int>> routes) {
    for(auto &cur : routes) {
        lines.push_back({cur[1], cur[0]});
    }
    
    sort(lines.begin(), lines.end());
    
    
    int ans{1}, cur{lines[0].X};
    
    for(int i = 1; i < lines.size(); i++) {
        auto [cy, cx] = lines[i];
        if(cx <= cur && cur <= cy) continue;
        cur = cy;
        ans++;
    }
    
    return ans;
}












