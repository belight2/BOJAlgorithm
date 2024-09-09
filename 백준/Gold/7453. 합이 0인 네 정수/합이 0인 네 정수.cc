#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
vector<ll> x, y;
ll a[4005], b[4005], c[4005], d[4005];
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            x.push_back(a[i] + b[j]);
            y.push_back(c[i] + d[j]);
        }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll res = 0;
    for(ll k : x){
        auto ub = upper_bound(y.begin(), y.end(), -k);
        auto lb = lower_bound(y.begin(), y.end(), -k);
        res += ub - lb;
    }
    cout << res;

}