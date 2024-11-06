#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<long long> solution(int x, int n) {
    vector<ll> ans(n, x);
    partial_sum(ans.begin(), ans.end(), ans.begin());
    return ans;
}