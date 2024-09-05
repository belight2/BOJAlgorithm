#include <iostream>
#include <vector>
using namespace std;
int a[100005];
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<bool> part(n+1, false);
    part[a[0]] = true;
    int en = 1; long long ans = 0;
    for(int st = 0; st < n; st++){
        while(en < n && !part[a[en]]) part[a[en++]] = true;
        ans += en - st;
        part[a[st]] = false;
    }
    cout << ans;
}
