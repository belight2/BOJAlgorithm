#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
#define X first
#define Y second

priority_queue<pi> pq;

int solution(vector<int> s, int k) {
    for(int i = 0; i < k; i++) {
        pq.push({s[i], i});
    }
    
    int ans = pq.top().X;
    
    for(int i = k; i < s.size(); i++) {
        while(!pq.empty() && pq.top().Y <= i - k) {
            pq.pop();
        }
        pq.push({s[i], i});
        ans = min(ans, pq.top().X);
    }
    
    return ans;
}