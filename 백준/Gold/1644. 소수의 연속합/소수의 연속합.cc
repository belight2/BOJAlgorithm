#include <iostream>
#include <vector>
using namespace std;
vector<int> prime;
int N;
void eratos(int n){
    vector<bool> res(n+1, true);
    for(int i = 2; i*i <= n; i++){
        if(!res[i]) continue;
        for(int j = i * i; j <= n; j+= i) res[j] = false;
    }
    for(int i = 2; i <= n; i++) if(res[i]) prime.push_back(i);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    eratos(N);
    prime.push_back(0);
    int len = prime.size();
    int tot = prime[0], ans = 0, en = 1;
    for(int st = 0; st < len; st++){
        while(en <= len && tot < N){
            tot += prime[en++];
        }
        if(en == len+1) break;
        if(tot == N) ans++;
        tot -= prime[st];
    }
    cout << ans;
}