#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll MX = 1'000'000'000LL * 100'000LL;

bool solve(ll mx, int n, vector<int> &t) {
    ll cnt{};
    for(auto time : t) {
        cnt += mx / time;
    }
    return cnt >= n;
}

long long solution(int n, vector<int> times) {
    ll st{0}, en{MX + 1};
    while(st + 1 < en) {
        ll md = (st + en) >> 1;
        (solve(md, n, times) ? en : st) = md;
    }
    return en;
}