#include <iostream>
#include <algorithm>
using namespace std;
int n, s, a[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0x7fffffff;
    int st = 0, en = 1, tot = a[0];
    for(; st < n; st++){
        while(en <= n && tot < s ){
            en++;
            tot += a[en-1];
        }
        if(en == n+1) break;
        res = min(res, en - st);
        tot -= a[st];
    }
    if(res == 0x7fffffff) cout << 0;
    else cout << res;
}