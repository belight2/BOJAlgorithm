#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
#define pb push_back
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

const int dx[]{1, 0, -1, 0};
const int dy[]{0, 1, 0, -1};

int n;
vector<vector<char>> board;

vpi teacher, wall;
vb isused;

bool detect() {
    for(auto [tx, ty] : teacher) {
        for(int dir = 0; dir < 4; dir++) {
            int nx = tx + dx[dir];
            int ny = ty + dy[dir];
            while(0 <= nx && nx < n && 0 <= ny && ny < n && board[nx][ny] != 'O') {
                if(board[nx][ny] == 'S') {
                    return 1;
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }
    return 0;
}

bool solve(int idx, int k) {
    if(k == 3) {
        return !detect();
    }
    
    bool ret{};
    for(int i = idx; i < sz(wall); i++) {
        if(!isused[i]) {
            isused[i] = 1;
            board[wall[i].X][wall[i].Y] = 'O';
            ret |= solve(i, k + 1);
            board[wall[i].X][wall[i].Y] = 'X';
            isused[i] = 0;
        }
    }       
    return ret;
}

int main() {
    fastio(nullptr, false);

    cin >> n;
    vector<vector<char>>(n, vector<char>(n)).swap(board);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'X') {
                wall.pb({i, j});
            }
            if(board[i][j] == 'T') {
                teacher.pb({i, j});
            }
        }
    }

    vb(sz(wall)).swap(isused);
    cout << (solve(0, 0) ? "YES" : "NO");
}