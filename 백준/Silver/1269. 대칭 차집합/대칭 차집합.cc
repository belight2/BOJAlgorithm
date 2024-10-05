#include <bits/stdc++.h>
using namespace std;
unordered_set<int> a;
int n, m, x;
int cnt;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x;
        a.insert(x);
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        if(a.find(x) != a.end()) cnt++;
    }
    cout << n + m - 2 * cnt;
}