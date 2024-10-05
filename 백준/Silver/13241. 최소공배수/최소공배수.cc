#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll GCD(ll a, ll b){ return b ? GCD(b, a%b) : a; }
ll LCD(ll a, ll b){ if(a == 0 || b == 0) return a+b; return a / GCD(a, b) * b; }

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a{}, b{};
    cin >> a >> b;
    cout << LCD(a, b);
}