#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<long long> solution(int x, int n) {
    vector<ll> ans(n);
    iota(ans.begin(), ans.end(), 1);
    for(auto &a : ans)  a *= x;
    return ans;
}