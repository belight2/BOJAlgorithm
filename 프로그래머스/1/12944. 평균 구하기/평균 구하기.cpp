#include <bits/stdc++.h>

using namespace std;

double solution(vector<int> arr) {
    return accumulate(arr.begin(), arr.end(), 0) / (double)arr.size();
}