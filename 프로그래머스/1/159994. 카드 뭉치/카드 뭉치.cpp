#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> A, vector<string> B, vector<string> goal) {
    int l{}, r{}, idx{};
    while(l < A.size() && r < B.size()){
        if(idx >= goal.size() || (A[l] != goal[idx] && B[r] != goal[idx])) break;
        if(A[l] == goal[idx]){
            l++; idx++;
        }
        if(B[r] == goal[idx]){
            r++; idx++;
        }
    }
    
    while(l < A.size() && A[l] == goal[idx]){
        l++; idx++;
    }
    while(r < B.size() && B[r] == goal[idx]){
        r++; idx++;
    }
    return (idx == goal.size() ? "Yes" : "No");
}