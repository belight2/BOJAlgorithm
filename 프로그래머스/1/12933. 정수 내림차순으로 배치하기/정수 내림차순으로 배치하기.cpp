#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    string ans = to_string(n);
    sort(ans.rbegin(), ans.rend());
    return stoll(ans);
}