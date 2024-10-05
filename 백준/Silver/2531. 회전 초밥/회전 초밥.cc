#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const char nl = '\n';
int N, d, k, c;
int a[30005];
vector<int> chk(3005);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> d >> k >> c;
    for(int i = 0; i < N; i++) cin >>a[i];
    int ans = 0; 
    chk[c]++;
    int cnt = 1, len = 0, en = 0;
    for(int st = 0; st < N; st++){
        while(len < k){
            if(chk[a[en]]++ == 0) cnt++;
            en++; len++;
            if(en == N) en = 0;
        }
        ans = max(ans, cnt);
        if((--chk[a[st]]) == 0) cnt--;
        len--;
    }
    cout << ans;
}