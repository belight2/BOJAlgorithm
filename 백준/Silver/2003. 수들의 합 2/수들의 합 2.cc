#include <iostream>
using namespace std;
int n, m;
int a[10005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    int tot = a[0], en = 1;
    for(int st = 0; st < n; st++){
        while(en <= n && tot < m) tot += a[en++];
        if(en == n+1) break;
        if(tot == m) ans++;
        tot -= a[st]; 
    }
    cout << ans;
}