#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int ans{}, idx{};
    for(int x : B) {
        if(A[idx] < x) {
            ans++;
            idx++;
        }      
    }
    return ans;
}