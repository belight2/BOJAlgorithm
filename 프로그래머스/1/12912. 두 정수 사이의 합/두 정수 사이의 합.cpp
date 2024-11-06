#include <bits/stdc++.h>

using namespace std;

long long solution(int a, int b) {
    if(a > b) swap(a, b);
    long long ans{};
    for(int i = a; i <= b; i++) ans += i;
    return ans;
}