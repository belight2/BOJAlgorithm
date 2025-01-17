#include <bits/stdc++.h>

using namespace std;

template<typename T>
class SegmentTree {
    private:
        int n;
        T *tree;
    public:
        SegmentTree(vector<int> &a): n(a.size()) {
            tree = new T[n << 1];
            for(int i = 0; i < n; i++) {
                tree[i + n] = a[i];
            }
            for(int i = n - 1; i > 0; i--) {
                tree[i] = max(tree[i << 1], tree[i << 1 | 1]); 
            }
        }
    
        ~SegmentTree() {
            delete [] tree;
        }
    
        T query(int l, int r) {
            T ret{};
            for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if(l & 1) ret = max(ret, tree[l++]);
                if(r & 1) ret = max(ret, tree[--r]);
            }
            return ret;
        }
};

int solution(vector<int> s, int k) {
    SegmentTree<int> segtree(s);
    int st{0}, en{k};
    int ans = segtree.query(st, en);
    while(en < s.size()) {
        ans = min(ans, segtree.query(++st, ++en));
    } 
    return ans;
}