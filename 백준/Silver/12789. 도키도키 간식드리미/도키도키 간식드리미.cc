#include <bits/stdc++.h>

using namespace std;

int n, x;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    
    stack<int> stk;
    int cur = 1;
    
    for(int i = 0; i < n; i++){
        cin >> x;
        stk.push(x);
        while(stk.size() && stk.top() == cur){
            cur++;
            stk.pop();
        }
    }
    cout << (stk.size() ? "Sad" : "Nice");
}