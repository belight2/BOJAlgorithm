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

constexpr double PI = acos(-1.0);

int main() {
    fastio(nullptr, false);

    double ax, ay, ar, bx, by, br;
    cin >> ax >> ay >> ar >> bx >> by >> br;

    double d = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));

    double ans{};
    if(fabs(ar - br) >= d) {
        ans = PI * pow(min(ar, br), 2);
    }
    else if(ar + br > d){
        double x = acos( (pow(ar, 2) + pow(d, 2) - pow(br, 2)) / (2 * ar * d));
        double y = acos( (pow(br, 2) + pow(d, 2) - pow(ar, 2)) / (2 * br * d));

        double as = (pow(ar, 2) * x) - (pow(ar, 2) * sin(2 * x) / 2);
        double bs = (pow(br, 2) * y) - (pow(br, 2) * sin(2 * y) / 2);
        ans = as + bs;
    }

    cout << fixed << setprecision(3) << ans;
}