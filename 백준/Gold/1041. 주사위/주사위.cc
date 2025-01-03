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

const ll INF = 0x3f3f3f3f;

ll n;
ll dice[7];
ll two_faces = INF;
ll three_faces = INF;

ll solve() {
    if(n == 1) {
        return accumulate(dice, dice + 7, 0) - *max_element(dice, dice + 7);
    }
    if(n == 2) {
        return 4 * two_faces + three_faces * 4;
    }

    three_faces *= 4;
    two_faces *= (n - 1) * 4 + (n - 2) * 4;

    return two_faces + three_faces + *min_element(dice + 1, dice + 7) * ((n - 2) * (n - 2) + (n - 1) * (n - 2) * 4);
}

int main() {
    fastio(nullptr, false);

    cin >> n;
    for(int i = 1; i <= 6; i++) {
        cin >> dice[i];
    }

    for(int i = 1; i <= 6; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i == j || i + j == 7) continue;
            two_faces = min(two_faces, dice[i] + dice[j]);
            for(int k = 1; k <= 6; k++) {
                if(j == k || k == i || i + k == 7|| j + k == 7) continue;
                three_faces = min(three_faces, dice[i] + dice[j] + dice[k]);
            }
        }
    }
    
    cout << solve();
}