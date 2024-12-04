#include <bits/stdc++.h>

using namespace std;
using ll = long long;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    for(auto x : works) pq.push(x);
    
    while(n-- && pq.size()){
        auto cur = pq.top(); pq.pop();
        cur--;
        if(cur) pq.push(cur);
    }
    
    ll ans{};
    while(pq.size()){
        ll cur = pq.top(); pq.pop();
        ans += cur * cur;
    }
    
    return ans;
}