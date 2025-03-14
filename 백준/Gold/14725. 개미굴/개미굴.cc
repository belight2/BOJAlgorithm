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

class Trie{
    private:
        string value;
        int unused;
        map<string, Trie> nodes;

        bool is_exists(string &v) {
            return nodes.find(v) != nodes.end();
        }

    public:
        Trie(): value("") {}
        Trie(string &value): value(value) {}

        void insert(vs &v, int idx) {
            if(idx == sz(v)) {
                return;
            }

            string cur = v[idx];
            
            if(!is_exists(v[idx])) {
                nodes.insert({v[idx], Trie(v[idx])}); 
            }

            nodes[v[idx]].insert(v, idx + 1);
        }

        void print(int depth) {
            for(auto cur : nodes) {
                cout << string(depth << 1, '-') << cur.X << nl;
                cur.Y.print(depth + 1);
            }
        }

};

int n, k;

int main() {
    fastio(nullptr, false);
    
    Trie root;

    cin >> n;
    while(n--) {
        cin >> k;

        vs a(k);
        for(auto &str : a) {
            cin >> str;
        }

        root.insert(a, 0);
    }

    root.print(0);
}