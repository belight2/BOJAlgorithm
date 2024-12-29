#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    if(n > s) return vector<int>(1, -1);
    
    vector<int> a(n, s / n);
    auto it = a.end();
    it--;
    for(int i = 0; i < s % n; i++) {
        (*it)++;
        it--;
    }
    
    return a;
}