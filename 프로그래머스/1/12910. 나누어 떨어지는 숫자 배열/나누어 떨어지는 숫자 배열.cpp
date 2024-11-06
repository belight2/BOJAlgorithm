#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int d) {
    sort(arr.begin(), arr.end());
    vector<int> answer;
    for(auto x : arr) if(x % d) continue; else answer.push_back(x);
    if(answer.empty()) answer.push_back(-1);
    return answer;
}