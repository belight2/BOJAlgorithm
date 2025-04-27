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

int n;
int dice[10'005][6];
int d[10'005][6];

int main() {
    fastio(nullptr, false);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> dice[i][j];
        }
        cin >> dice[i][4] >> dice[i][5] >> dice[i][3];
    }

    for(int j = 0; j < 6; j++) {
        int mx{};
        for(int k = 0; k < 6; k++) {
            if(j != k && abs(j - k) != 3) {
                mx = max(mx, dice[1][k]);
            }
        }
        d[1][j] = mx;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 6; j++) {
            // j면이 윗면일 때 옆면 중 최대값 찾기
            int mx{};
            for(int k = 0; k < 6; k++) {
                if(j != k && abs(j - k) != 3) {
                    mx = max(mx, dice[i][k]);
                }
            }
            
            // i 주사위의 아랫면과 i - 1 주사위의 윗면 맞추기
            int bottom = j + (j < 3 ? 3 : -3);

            for(int k = 0; k < 6; k++) {
                if(dice[i - 1][k] == dice[i][bottom]) {
                    d[i][j] = max(d[i][j], d[i - 1][k] + mx);
                }
            }
        }
    }

    cout << *max_element(d[n], d[n] + 6);
}