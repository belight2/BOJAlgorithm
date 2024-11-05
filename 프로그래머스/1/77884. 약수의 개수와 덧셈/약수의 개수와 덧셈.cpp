#include <bits/stdc++.h>

using namespace std;

int solution(int left, int right) {
    vector<int> s;
    for(int i = 1; i * i <= 1000; i++) s.push_back(i * i);
    
    int ans{};
    for(int i = left; i <= right; i++){
        ans += (binary_search(s.begin(), s.end(), i)) ? -i : i;
    }
    return ans;
}