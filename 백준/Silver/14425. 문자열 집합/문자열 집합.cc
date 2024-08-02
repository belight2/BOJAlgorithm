#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
unordered_map<string, bool> h;
string str;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    while(n--){
        cin >> str;
        h[str] = 1;
    }
    while(m--){
        cin >> str;
        if(h.find(str) == h.end()) continue;
        ans++;
    }
    cout << ans;
}