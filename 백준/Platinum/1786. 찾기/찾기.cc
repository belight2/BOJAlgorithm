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

class KMP{
    private:
        const string src;
        const string dst;
        vi start_poses;
        vi fail;

        void construct_fail_function() {
            int j{};
            for(int i = 1; i < sz(dst); i++) {
                while(j > 0 && dst[i] != dst[j]) j = fail[j - 1];
                if(dst[i] == dst[j]) fail[i] = ++j;
            }    
        }

        void find() {
            int j{};
            for(int i = 0; i < sz(src); i++) {
                while(j > 0 && src[i] != dst[j]) j = fail[j - 1];
                if(src[i] == dst[j]) j++;
                if(j == sz(dst)) {
                    start_poses.pb(i - j + 2);
                    j = fail[j - 1];
                }
            }
        }

    public:
        KMP(const string &src, const string &dst): src(src), dst(dst), fail(dst.size()) { 
            construct_fail_function();
            find();
        }

        bool is_exists() {
            return !start_poses.empty();
        }

        size_t size() {
            return start_poses.size();
        }

        int get(int idx) {
            return start_poses[idx];
        }
};

string t, p;

int main() {
    fastio(nullptr, false);
    getline(cin, t);
    getline(cin, p);

    KMP kmps = KMP(t, p);

    cout << kmps.size() << nl;
    for(int i = 0; i < kmps.size(); i++) {
        cout << kmps.get(i) << ' ';
    }
}