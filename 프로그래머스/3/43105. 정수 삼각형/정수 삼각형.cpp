#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int mxdep;
int d[505][505];

int solution(vector<vi> t) {
    mxdep = t.size();
    d[0][0] = t[0][0];
    for(int i = 1; i < mxdep; i++){
        for(int j = 0; j <= i; j++){
            d[i][j] = t[i][j] + max(d[i-1][(j == i ? j-1 : j)], d[i-1][max(0, j-1)]);
        }
    }
    return *max_element(d[mxdep-1], d[mxdep-1]+mxdep);
}
