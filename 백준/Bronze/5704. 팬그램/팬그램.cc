#include <bits/stdc++.h>

using namespace std;

string s;
void solve(){
    int cnt{};
    vector<bool> chk(26);    
    for(auto c : s){
        if(!isalpha(c) || chk[c-'a']) continue;
        chk[c-'a'] = 1;
        cnt++;
    }
    cout << (cnt == 26 ? "Y\n"  : "N\n");
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    while(getline(cin, s), s != "*") solve();    
}