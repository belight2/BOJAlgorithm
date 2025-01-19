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

// startTime: 13:14
// submissionTime: 13:16 (3% MLE)
// submissionTime: 15:41 

ll n, k;

int main() {
    fastio(nullptr, false);
    
    cin >> n >> k;

    int digit{1};
    ll tot{};
    for(ll offset = 9; digit <= 9; offset *= 10L, digit++) {
        if(k <= tot + offset * digit) {
            break;
        }
        tot += offset * digit;
    }

    ll k_num{1};
    for(int i = 1; i < digit; i++) k_num *= 10;
    k -= tot + 1;
    k_num += (k / digit);

    if(n < k_num) {
        cout << -1;
        return 0;
    }

    cout << to_string(k_num)[k % digit];
}