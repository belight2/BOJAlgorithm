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

class Node{
    private:
        int score;
        Node *red_nxt;
        Node *blue_nxt;

    public:
        Node(): score(0), red_nxt(nullptr), blue_nxt(nullptr) {}

        Node(int score, Node *red_nxt): score(score), red_nxt(red_nxt), blue_nxt(nullptr) {}

        Node(int score, Node *red_nxt, Node *blue_nxt): score(score), red_nxt(red_nxt), blue_nxt(blue_nxt) {}

        Node *move(int offset) {
            Node *cur = this;
            
            if(offset && blue_nxt) {
                offset--;
                cur = cur->blue_nxt;
            }

            while(offset-- && cur) {
                cur = cur->red_nxt;
            }

            return cur;            
        }

        void setBlue(Node *blue_nxt) {
            this -> blue_nxt = blue_nxt;
        }

        int getScore() {
            return score;
        }
};

vi dice(10);
Node *st;
vector<Node*> horse;

int ans{};

void construct_node() {
    Node *prv_end = new Node(40, nullptr);
    
    vector<Node*> blue;
    Node *nxt = prv_end;
    for(int i = 19; i >= 1; i--) {
        Node *cur = new Node(i * 2, nxt);
        if(i % 5 == 0) {
            blue.push_back(cur);
        }
        nxt = cur;
    }
    st = new Node(0, nxt);

    nxt = prv_end;
    for(int i = 35; i >= 25; i -= 5) {
        Node *cur = new Node(i, nxt);
        nxt = cur;
    }

    Node *center = nxt;

    pi init[]{{26, 1}, {24, -2}, {19, -3}};    
    for(int i = 0; i < 3; i++) {
        nxt = center;
        auto [sc, offset] = init[i];
        while(sc != blue[i]->getScore() - (i == 0)) {
            Node *cur = new Node(sc, nxt);
            nxt = cur;
            sc += offset;
        }
        blue[i]->setBlue(nxt);
    }

}


bool is_occupied(Node *cur) {
    bool ret = 0;
    for(int i = 0; i < 4; i++) {
        ret |= cur == horse[i];
    }
    return ret;
}

void solve(int idx, int sc) {    
    ans = max(ans, sc);

    if(idx == 10) {
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        if(!horse[i]) {
            continue;
        }

        Node *cur = horse[i];
        Node *nxt = horse[i] -> move(dice[idx]);
        
        if(!nxt || !is_occupied(nxt)) {
            horse[i] = nxt;
            solve(idx + 1, sc + (nxt ? nxt -> getScore() : 0));
            horse[i] = cur;
        }
    }
}

int main() {
    fastio(nullptr, false);

    for(auto &x : dice) cin >> x;

    construct_node();
    
    for(int i = 0; i < 4; i++) {
        horse.pb(st);    
    }

    solve(0, 0);

    cout << ans;
}