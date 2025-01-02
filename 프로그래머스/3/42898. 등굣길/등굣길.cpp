#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int dx[2] = { 1, 0 };
const int dy[2] = { 0, 1 };

ll MOD = 1e9 + 7;
bool chk[105][105];
ll d[105][105];

ll solve(int cx, int cy, int &n, int &m) {
    if(cx == n && cy == m) {
        return 1;
    }
    
    if(d[cx][cy] != -1) {
        return d[cx][cy];
    }
    
    d[cx][cy] = 0;
    for(int dir = 0; dir < 2; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if(nx > n || ny > m || chk[nx][ny]) continue;
        d[cx][cy] = (d[cx][cy] + solve(nx, ny, n, m)) % MOD;
    }
    return d[cx][cy];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    memset(d, -1, sizeof(d));
    for(auto &x : puddles) {
        chk[x[0]][x[1]] = 1;
    }
    
    return solve(1, 1, m, n);
}