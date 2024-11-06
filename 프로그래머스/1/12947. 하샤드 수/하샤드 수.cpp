#include <bits/stdc++.h>

using namespace std;

bool solution(int x) {
    string X = to_string(x);
    return !(x % (accumulate(X.begin(), X.end(), 0) - '0' * X.size()));
}