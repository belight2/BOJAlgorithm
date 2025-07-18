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
string str;

int a[30];

int main() {
    fastio(nullptr, false);

    cin >> n >> str;
    
    int ans{}, cnt{}, en{};
    for(int st = 0; st < sz(str); st++) {
        while(en != sz(str) && (cnt < n || a[str[en] - 'a'])) {
            int &cur = a[str[en] - 'a'];
            cnt += cur == 0;
            cur++;
            en++;
        }
        ans = max(ans, en - st);  
        int &prv = a[str[st] - 'a'];
        prv--;
        cnt -= prv == 0;
    }

    cout << ans;
}