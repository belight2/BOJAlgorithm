#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    int mn = *min_element(arr.begin(), arr.end());
    vector<int> ans;
    for(auto x : arr) if(x != mn) ans.push_back(x);
    if(ans.empty()) ans.push_back(-1);
    return ans;
}