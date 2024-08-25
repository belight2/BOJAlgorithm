#include <bits/stdc++.h>

using namespace std;

using pi = pair<int,int>;
#define X first
#define Y second

class mxcmp{
    public:
        bool operator()(const pi &a, const pi &b){
            if(a.X == b.X) return a.Y > b.Y;
            return b.X > a.X;
        }
};

priority_queue<pi, vector<pi>, mxcmp> mxpq;
priority_queue<pi, vector<pi>, greater<pi>> mnpq;
bool vis[1'000'000];

void delete_invalid_index(){
    while(mxpq.size() && vis[mxpq.top().Y]){
        cout << "unvalid index" << mxpq.top().Y << '\n';
        mxpq.pop();
    }
    while(mnpq.size() && vis[mnpq.top().Y]){
        cout << "unvalid index" << mnpq.top().Y << '\n';
        mnpq.pop();
    }
}

vector<int> solution(vector<string> oper) {
    int n{};
    for(auto &cur : oper){
        auto cmd = cur[0];
        int num = stoi(string(cur.begin()+2, cur.end()));
        delete_invalid_index();
        if(cmd == 'I'){
            mxpq.push({num, n});
            mnpq.push({num, n});
            n++;
        }
        else{
            if(num == -1 && mnpq.size()) {
                vis[mnpq.top().Y] = 1;
                mnpq.pop();
            }
            else if(num == 1 && mxpq.size()){
                vis[mxpq.top().Y] = 1;
                mxpq.pop();
            }
        }
    }
    delete_invalid_index();
    
    if(mxpq.empty() || mnpq.empty()) return {0, 0};
    return {mxpq.top().X, mnpq.top().X};
}