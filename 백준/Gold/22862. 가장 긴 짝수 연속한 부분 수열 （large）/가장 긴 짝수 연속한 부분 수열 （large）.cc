#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int a[1000005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(a, a+1000005, -1);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    int en = 0, ign = 0;
    for(int st = 0; st < n; st++){
        while(en < n && ign <= k) if(a[en++]&1) ign++;
        res = max(res, en - st - ign);
        if(a[st]&1 && ign > 0) ign--;
    }
    cout << res;
}