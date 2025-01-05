#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
#define X first
#define Y second

vector<pi> segment;

int solution(int n, vector<int> stations, int w) {
    for(auto &cx : stations) {
        segment.push_back({max(1, cx - w), min(n, cx + w)});
    }
    
    vector<pi> part;
    part.push_back({0, 0});
    auto [tx, ty] = segment[0];
    for(auto [cx, cy] : segment) {
        if(tx <= cx && cx <= ty) {
            ty = cy;
            continue;
        }
        part.push_back({tx, ty});
        tx = cx;
        ty = cy;
    }
    part.push_back({tx, ty});
    part.push_back({n+1, n+1});
    
    w = (w << 1) + 1;
    
    int ans{};
    for(int i = 1; i < part.size(); i++) {
        int dist = part[i].X - part[i - 1].Y - 1; 
        ans += dist / w;
        ans += (dist % w != 0);
    }
    
    return ans;
}












