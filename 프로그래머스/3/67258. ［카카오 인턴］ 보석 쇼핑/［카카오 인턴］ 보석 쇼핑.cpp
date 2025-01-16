#include <bits/stdc++.h>

using namespace std;

int mx;
unordered_map<string, int> idx;

vector<int> solution(vector<string> G) {
    for(auto x : G) {
        if(idx.find(x) == idx.end()) {
            idx[x] = mx++;
        }
    }
    
    int ansx{0}, ansy{100'000};
    int cnt{}, en{};
    vector<int> chk(mx);
    for(int st = 0; st < G.size(); st++) {
        while(en < G.size() && cnt < mx) {
            if(!chk[idx[G[en]]]) cnt++;
            chk[idx[G[en]]]++;
            en++;
        }
        
        if(cnt == mx && ansy - ansx > en - st) {
            ansx = st;
            ansy = en;
        }
        
        chk[idx[G[st]]]--;
        if(!chk[idx[G[st]]]) cnt--;
    }
    
    return {ansx+1, ansy};
}