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

using pd = pair<double, double>;
using td = tuple<double, int, int>;

int n;
vector<pd> stars;
vector<td> edges;

vi p(100, -1);

int find(int x) {
    return (p[x] < 0 ? x : p[x] = find(p[x]));
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) {
        return 0;
    }

    if(--p[x] > p[y]) {
        swap(x, y);
    }

    p[y] = x;
    return 1;
}

double cal_distance(pd &a, pd &b) {
    double dx = a.X - b.X;
    double dy = a.Y - b.Y;
    return dx * dx + dy * dy;
}

int main() {
    fastio(nullptr, false);

    cin >> n;

    vector<pd> (n).swap(stars);
    for(auto &[x, y] : stars) {
        cin >> x >> y;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            edges.pb({cal_distance(stars[i], stars[j]), i, j});
        }
    }

    sort(all(edges)); 

    double ans{};
    for(auto &[dist, u, v] : edges) {
        if(merge(u, v)) {
            ans += sqrt(dist);
        }
    } 

    cout.precision(3);
    cout << ans;
}