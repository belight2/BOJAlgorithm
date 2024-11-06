#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    vector<int> a, b;
    for(int i = 0; i < signs.size(); i++){
        (signs[i] ? a : b).push_back(absolutes[i]);
    }
    return accumulate(a.begin(), a.end(), 0) - accumulate(b.begin(), b.end(), 0);
}