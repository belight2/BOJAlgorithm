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

string str;

bool is_palindrome(int st, int en) {
    while(st < en) {
        if(str[st] == str[en]) {
            st++; en--;
            continue;
        }
        return 0;
    }
    return 1;
}

void solve(int tc) {
    cin >> str;

    int ans{-1};
    int st{}, en{sz(str) - 1};
    while(st < en) {
        if(str[st] == str[en]) {
            st++; en--;
            continue;
        }

        if(ans == -1 && (is_palindrome(st + 1, en) || is_palindrome(st, en - 1))) {
            ans = 1;
            break;
        }

        ans = 2;
        break;
    }

    cout << max(ans, 0) << nl;
}

int main() {
    fastio(nullptr, false);
    int tc{};
    cin >> tc;
    for(int i = 1; i <= tc; i++) solve(i);
}