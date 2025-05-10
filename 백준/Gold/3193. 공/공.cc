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

int n, k;
char board[4][1010][1010];
pi pos[4][1010][1010];
pi ball;

void rotate(int cur) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[cur][i][j] = board[cur - 1][n - j - 1][i];
        }
    }
}

int main() {
    fastio(nullptr, false);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[0][i][j];
            if(board[0][i][j] == 'L') {
                ball = {i, j};
                board[0][i][j] = '.';
            }
        }
    }

    for(int i = 1; i <= 3; i++) {
        rotate(i);
    }

    for(int dir = 0; dir < 4; dir++) {
       for(int col = 0; col < n; col++) {
            int row = n - 1;
            pi fall = {row, col};
            while(row >= 0) {
                if(board[dir][row][col] == 'X') {
                    fall = {row - 1, col};
                    row--;
                    continue;
                }
                pos[dir][row][col] = fall;
                row--;
            }
       } 
    }
    
    int dir = 0;
    char cmd;
    while(k--) {
        cin >> cmd;
        dir = (dir + (cmd == 'L' ? 3 : 1)) % 4;
        for(int i = 0; i < (cmd == 'L' ? 1 : 3); i++) {
            ball = {n - ball.Y - 1, ball.X};
        }
        ball = pos[dir][ball.X][ball.Y];
    }
    
    board[dir][ball.X][ball.Y] = 'L';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[dir][i][j];
        }
        cout << nl;
    }
}