#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int st = 0, en = 0;
    int res = 0x7fffffff;
    while(en < n && st < n){
        int cur = a[en] - a[st];
        if(cur >= m){
            res = min(res, cur);
            st++;    
        }
        else en++;
    }
    cout << res;
}