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

const int MX = 100'000;

pair<int, bool> buttonA(int cur) {
    return {cur + 1, cur + 1 >= MX};
}

pair<int, bool> buttonB(int cur) {
    int nxt = cur * 2;
   
    string num = to_string(nxt);
    for(char &c : num) {
        if(c != '0') {
            c -= 1;
            break;
        }
    }
    
    nxt = stoi(num);
    return {nxt, cur * 2 >= MX || nxt >= MX};
}

int n, t, g;
int d[1'000'005];
pair<int, bool> (*func[])(int) = {buttonA, buttonB};

int main() {
    fastio(nullptr, false);

    memset(d, -1, sizeof(d));
    
    cin >> n >> t >> g;

    qi q;
    d[n] = 0;
    q.push(n);
    while(sz(q)) {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 2; dir++) {
            auto [nxt, chk] = func[dir](cur);

            if(!chk && (d[nxt] == -1 || d[nxt] > d[cur] + 1)) {
                d[nxt] = d[cur] + 1;
                q.push(nxt);
            }
        }
    }

    cout << (d[g] != -1 && d[g] <= t ? to_string(d[g]) : "ANG");
}