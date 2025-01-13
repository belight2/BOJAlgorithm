#include <bits/stdc++.h>

using namespace std;

int n;
int d[2][100'010];

int solution(vector<int> s)
{   
    n = s.size();
    
    if(n == 1) {
        return s[0];
    }
    if(n == 2) {
        return max(s[0], s[1]);
    }
    
    d[0][0] = d[0][1] = s[0];
    d[1][0] = 0;
    d[1][1] = s[1];
    for(int i = 0; i < 2; i++) {
        for(int j = 2; j < n - (!i); j++) {
            d[i][j] = max(d[i][j - 1], d[i][j - 2] + s[j]);
        }
    }
    
    return max(d[0][n - 2], d[1][n - 1]);
}