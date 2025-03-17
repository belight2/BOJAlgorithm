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

int n, m;
vi a;

template<typename T>
class SegmentTree {
    private:
        const int n;
        vi a;
        T *tree;
    
    public:
        SegmentTree(vector<T> &a) : n(a.size()), a(a) {
            tree = new T[n << 1];
            for(int i = 0; i < n; i++) tree[n + i] = i;
            for(int i = n - 1; i > 0; i--) {
                if(a[tree[i << 1]] == a[tree[i << 1 | 1]]) {
                    tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
                    continue;
                }
                tree[i] = (a[tree[i << 1]] < a[tree[i << 1 | 1]] ? tree[i << 1] : tree[i << 1 | 1]);
            }
        }

        ~SegmentTree() {
            delete [] tree;
        }

        void update_point(int p, T val) {
            a[p] = val;
            for(p += n; p > 1; p >>= 1) {
                if(a[tree[p]] == a[tree[p ^ 1]]) {
                    tree[p >> 1] = min(tree[p], tree[p ^ 1]);
                    continue;
                }
                tree[p >> 1] = (a[tree[p]] < a[tree[p ^ 1]] ? tree[p] : tree[p ^ 1]);
            }
        }

        int get() {
            return tree[1];
        }
};

int main() {
    fastio(nullptr, false);

    cin >> n;

    vi (n).swap(a);
    for(auto &x : a) {
        cin >> x;
    }

    SegmentTree<int> seg(a);
    
    cin >> m;
    while(m--) {
        int cmd;
        cin >> cmd;

        if(cmd & 1) {
            int idx, x;
            cin >> idx >> x;
            seg.update_point(idx - 1, x);
        } 
        else {
            cout << seg.get() + 1 << nl;
        }
    }
}