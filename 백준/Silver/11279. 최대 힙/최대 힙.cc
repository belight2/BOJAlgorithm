#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int n, x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(n--){
        cin >> x;
        if(!x){
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else cout << "0\n";
        }
        else pq.push(x);
    }
}