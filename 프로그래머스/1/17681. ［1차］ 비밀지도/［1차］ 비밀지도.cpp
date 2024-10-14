#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> A, vector<int> B) {
    vector<string> ans(n);
    
    cout << ans[0] << '\n';
    
    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j--){
            if(((A[i] >> j) & 1) | ((B[i] >> j) & 1)) ans[i].push_back('#');
            else ans[i].push_back(' ');
        }
    }
    
    return ans;
}