#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<string, bool> h;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    while(n--){
        string str;
        cin >> str;
        h[str] = 1;
    }
    int ans{};
    while(m--){
        string str;
        cin >> str;
        if(h.find(str) == h.end()) continue;
        ans++;
    }
    cout << ans;
}