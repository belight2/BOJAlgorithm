#include <bits/stdc++.h>

using namespace std;

int n, cmd, x;
stack<int> stk;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == 1){
            cin >> x;
            stk.push(x);
        }
        else if(cmd == 2){
            if(stk.size()){
                cout << stk.top() << '\n';
                stk.pop();
            }
            else cout << -1 << '\n';
        }
        else if(cmd == 3){
          cout << stk.size() << '\n';  
        }
        else if(cmd == 4){
            cout << stk.empty() << '\n';
        }
        else if(cmd == 5){
            cout << (stk.size() ? stk.top() : -1) << '\n';
        }
    }
}