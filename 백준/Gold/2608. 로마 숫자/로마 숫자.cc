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

vi arabia_numbers = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
vs roma_numbers = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

// 아라비아 숫자 -> 로마 숫자 변환
string convert_r_num(int number) {
    string ret{};
    while(number) {
        for(int i = 0; i < sz(arabia_numbers); i++) {
            if(number < arabia_numbers[i]) continue;
            number -= arabia_numbers[i];
            ret += roma_numbers[i];
            break;
        }
    }
    return ret;
}

// 로마 숫자 -> 아라비아 숫자 변환
int convert_a_num(const string &number) {
    int n = sz(number);

    bool flag{};
    int ans{}, idx{};   
    while(idx < n - 1) {
        string cur = string(1, number[idx]);
        cur.push_back(number[idx + 1]);

        int fdx = find(all(roma_numbers), cur) - roma_numbers.begin();

        if(fdx != sz(arabia_numbers)) {
            ans += arabia_numbers[fdx];
            idx += 2;
            continue;
        }        

        cur.pop_back();
        fdx = find(all(roma_numbers), cur) - roma_numbers.begin();
        ans += arabia_numbers[fdx];
        idx++;
    }

    if(idx == n - 1) {  
        int fdx = find(all(roma_numbers), string(1, number[n - 1])) - roma_numbers.begin();
        ans += arabia_numbers[fdx];
    }

    return ans;
}

int main() {
    fastio(nullptr, false);
    string a, b;
    cin >> a >> b;

    int ans = convert_a_num(a) + convert_a_num(b);

    cout << ans << nl << convert_r_num(ans);
}