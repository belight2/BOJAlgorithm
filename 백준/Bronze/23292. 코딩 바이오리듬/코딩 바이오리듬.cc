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

int m;
string birth;
vs coding;

int solve(string cur) {
    int year{0}, month{0}, day{0}, x{};
    for(int i = 0; i < 4; i++) {
        x = birth[i] - cur[i];
        year += x * x;
    }
    for(int i = 4; i < 6; i++) {
        x = birth[i] - cur[i];
        month += x * x;
    }
    for(int i = 6; i < 8; i++) {
        x = birth[i] - cur[i];
        day += x * x;
    }
    return year * month * day;
}

int main() {
    fastio(nullptr, false);

    cin >> birth >> m;
    vs (m).swap(coding);    
    for(auto &x : coding) {
        cin >> x;
    }
    sort(all(coding));

    int mx{0};
    string ans;
    for(int i = 0; i < m; i++) {
        int k = solve(coding[i]);
        if (mx < k) {
            mx = k;
            ans = coding[i];
        }
    }

    cout << ans;
}