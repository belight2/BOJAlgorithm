#include <bits/stdc++.h>

using namespace std;

int n, cmd, x;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    deque<int> dq;
    while(n--){
        cin >> cmd;
        if(cmd == 1){
            cin >> x;
            dq.push_front(x);
        }
        else if(cmd == 2){
            cin >> x;
            dq.push_back(x);
        }
        else if(cmd == 3){
            if(dq.size()){
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else cout << -1 << '\n';
        }
        else if(cmd == 4){
            if(dq.size()){
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else cout << -1 << '\n';
        }
        else if(cmd == 5){
            cout << dq.size() << '\n';
        }
        else if(cmd == 6){
            cout << dq.empty() << '\n';
        }
        else if(cmd == 7){
            cout << (dq.size() ? dq.front() : -1) << '\n';
        }
        else{ //cmd == 8
            cout << (dq.size() ? dq.back() : -1) << '\n';
        }
    }
}