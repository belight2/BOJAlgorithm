#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int ans{};
    for(int i = 1; i * i <= n; i++){
        if(n % i) continue;
        ans += i;
        if(i != n / i) ans += n / i;
    }
    return ans;
}