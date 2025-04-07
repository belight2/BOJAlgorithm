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

const int LEFT = 6;
const int RIGHT = 2;

int n, k;
deque<int> wheel[1005];
int d[1005];

void decide_diretion(int cur, int dir) {
    memset(d, 0, sizeof(d));
    d[cur] = dir;
    for(int i = cur; i < n - 1; i++) {
        if(wheel[i][RIGHT] == wheel[i + 1][LEFT]) {
            break;
        }
        d[i + 1] = d[i] * -1;
    }

    for(int i = cur; i > 0; i--) {
        if(wheel[i][LEFT] == wheel[i - 1][RIGHT]) {
            break;
        }
        d[i - 1] = d[i] * -1; 
    }
}

void rotate(int idx, int dir) {
    decide_diretion(idx, dir);

    for(int i = 0; i < n; i++) {
        if(!d[i]) {
            continue;
        }

        if(d[i] < 0) {
            wheel[i].pb(wheel[i].front());
            wheel[i].pop_front();
        }
        else {
            wheel[i].push_front(wheel[i].back());
            wheel[i].pop_back();
        }
    }
}

int main() {
    fastio(nullptr, false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        string cur;
        cin >> cur;
        for(int j = 0; j < sz(cur); j++) {
            wheel[i].pb(cur[j] - '0');
        }
    }
    
    cin >> k;
    while(k--) {
        int idx, dir;
        cin >> idx >> dir;
        rotate(idx - 1, dir);
    }

    int ans{};
    for(int i = 0; i < n; i++) {
        ans += wheel[i].front();
    }

    cout << ans;
}