#include <bits/stdc++.h>
#define sz(x) int((x).size())

using namespace std;

vector<int> ans;

bool chk(string &a, string &b){
    int n = sz(a);
    for(int i = 0; i < n; i++){
        if(a[i] == '*') continue;
        if(a[i] != b[i]) return 0;
    }
    return 1;
}

void func(int k, int vis, vector<string> &user, vector<string> &ban){
    if(k == sz(ban)){
        ans.push_back(vis);
        return;
    }
    for(int i = 0; i < sz(user); i++){
        if((vis>>i)&1) continue;
        if(sz(ban[k]) != sz(user[i])) continue;
        if(!chk(ban[k], user[i])) continue;
        vis |= (1 << i);
        func(k+1, vis, user, ban);
        vis &= (~(1 << i));
    }
}

int solution(vector<string> user, vector<string> ban) {
    func(0, 0, user, ban);
    sort(ans.begin(), ans.end());
    return unique(ans.begin(), ans.end()) - ans.begin();
}