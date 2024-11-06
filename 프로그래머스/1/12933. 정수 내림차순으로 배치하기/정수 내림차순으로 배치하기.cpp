#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    string ans{};
    while(n){
        ans.push_back('0' + n % 10);
        n /= 10;
    }
    sort(ans.rbegin(), ans.rend());
    return stoll(ans);
}