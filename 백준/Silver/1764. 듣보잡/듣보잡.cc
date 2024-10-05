#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    unordered_set<string> hash;
    string s;
    while(m--){
        cin >> s;
        hash.insert(s);
    }
    vector<string> res;
    for(int i = 0; i < n; i++){
        auto it = hash.find(a[i]);
        if(it == hash.end()) continue;
        res.push_back(*it);
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(string x : res) cout << x << '\n';
}
