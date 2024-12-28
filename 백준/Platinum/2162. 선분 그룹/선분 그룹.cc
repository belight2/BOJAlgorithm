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

template<typename T>
class Point{
    private:
        T x, y;

    public:
        Point() {}
        Point(T x, T y): x(x), y(y) { }

        int ccw(const Point<T> &a, const Point<T> &b) {
            T cross = (x * a.y + a.x * b.y + b.x * y) - (a.x * y + x * b.y + b.x * a.y);
            if(!cross) return 0;
            return (cross < 0 ? -1 : 1);
        }

        bool operator<=(const Point<T> &other) const {
            return this -> x < other.x || (this -> x == other.x && this -> y <= other.y);
        }
};

template<typename T>
class Line{
    private:
        Point<T> a;
        Point<T> b;
        bool is_inner(const Point<T> &c) {
            return a <= c && c <= b;
        }

    public:
        Line() {}
        Line(T ax, T ay, T bx, T by): a(ax, ay), b(bx, by) {
            if(b <= a) {
                swap(a, b);
            }
        }

        int ccw(Point<T> c) {
            return a.ccw(b, c);
        }

        bool is_intersection(Line other) {
            T this_cross = 1, other_cross = 1;
            for(int i = 0; i < 4; i++) {
                T cur = (i < 2 ? ccw(i ? other.b : other.a) : other.ccw(i == 2 ? a : b));
                if(!cur && (i < 2 ? is_inner(i ? other.b : other.a) : other.is_inner(i == 2 ? a : b))) return 1;
                (i < 2 ? this_cross : other_cross) *= cur;
            }
            return (this_cross < 0 && other_cross < 0);
        }
};

vi p(3001, -1);

int find(int x) {
    return (p[x] < 0 ? x : p[x] = find(p[x]));
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
}

int n;
vector<Line<int>> lines;

int main() {
    fastio(nullptr, false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        lines.pb(Line<int>(a, b, c, d));
    }    

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(lines[i].is_intersection(lines[j])) {
                merge(i, j);
            }
        }
    }

    int cnt{}, ans{};
    for(int i = 0; i < n; i++) {
        if(p[i] >= 0) continue;
        cnt++;
        ans = max(abs(p[i]), ans);
    }

    cout << cnt << nl << ans;
}