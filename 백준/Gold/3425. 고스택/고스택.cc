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
#define pf push_front
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

const ll NUM_MAX = 1e9;

const vs UNARY{"POP", "INV", "DUP"};
const vs BINARY{"SWP", "ADD", "SUB", "MUL", "DIV", "MOD"};

bool chk_validate(string &cmd, int size) {
    if(find(all(UNARY), cmd) != UNARY.end()) {
        return size;
    }
    if(find(all(BINARY), cmd) != BINARY.end()) {
        return size >= 2;
    }
    return "NUM" == cmd.substr(0, 3);
}

ll cal(string &cmd, ll lhs, ll rhs) {
    if(cmd == "ADD") {
        return lhs + rhs;
    }
    if(cmd == "SUB") {
        return lhs - rhs;
    }
    if(cmd == "MUL") {
        return lhs * rhs;
    }
    if(cmd == "DIV") {
        return (rhs == 0 ? NUM_MAX + 10 : lhs / rhs);
    }
    if(cmd == "MOD") {
        return (rhs == 0 ? NUM_MAX + 10 : (abs(lhs) % abs(rhs))) * (lhs < 0 ? -1 : 1);
    }
}

bool process(deque<ll> &stk, string &cmd) {
    if(!chk_validate(cmd, sz(stk))) {
        return 0;
    }

    if(cmd == "POP") {
        stk.pop_front();
    }
    else if(cmd == "INV") {
        stk.front() = -stk.front();
    }
    else if(cmd == "DUP") {
        stk.push_front(stk.front());
    }
    else if(cmd == "SWP") {
        swap(stk[1], stk[0]);
    }
    else if(cmd == "ADD" || cmd == "SUB" || cmd == "MUL" || cmd == "DIV" || cmd == "MOD") {
        ll nxt = cal(cmd, stk[1], stk[0]);
        stk.pop_front();
        stk.pop_front();
        stk.push_front(nxt);
        return abs(nxt) <= NUM_MAX;
    }
    else {
        int nst = cmd.find(' ') + 1;
        ll nxt = stoll(cmd.substr(nst, sz(cmd) - nst));
        stk.push_front(nxt);
    }
    return 1;
}

void execute(vs &program, int init) {
    deque<ll> stk;
    stk.pb(init);
    for(auto &cmd : program) {
        if(!process(stk, cmd)) {
            cout << "ERROR" << nl;
            return;
        }
    }

    if(sz(stk) == 1) {
        cout << stk[0] << nl;
    }
    else {
        cout << "ERROR\n";
    }
}

int main() {
    fastio(nullptr, false);
    
    string cmd;
    while(getline(cin, cmd), cmd != "QUIT") {
        vs program;
        while(cmd != "END") {
            program.pb(cmd);
            getline(cin, cmd);
        }

        int cnt;
        cin >> cnt;
        while(cnt--) {
            int v;
            cin >> v;
            execute(program, v);
        }
        cout << nl;

        getline(cin, cmd);
        cin.ignore(1);
    }
}