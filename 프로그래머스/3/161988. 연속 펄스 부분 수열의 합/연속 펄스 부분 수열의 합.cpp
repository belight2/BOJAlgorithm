#include <bits/stdc++.h>

using namespace std;

int n;

long long solution(vector<int> a) {
    n = a.size();
    long long ans{}, tot{};
    for(int i = 0; i < n; i++) {
        int cur = a[i] * (i % 2 == 0 ? 1 : -1);
        if(tot + cur <= 0) {
            tot = 0;
            continue;
        } 
        tot += cur;
        ans = max(ans, tot);
    }
    tot = 0;
    for(int i = 0; i < n; i++) {
        int cur = a[i] * (i % 2 == 0 ? -1 : 1);
        if(tot + cur <= 0) {
            tot = 0;
            continue;
        } 
        tot += cur;
        ans = max(ans, tot);
    }
    return ans;
}