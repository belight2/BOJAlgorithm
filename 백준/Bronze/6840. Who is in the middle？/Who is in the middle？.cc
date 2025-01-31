#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    priority_queue<int> pq;

    for(int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    pq.pop();
    cout << pq.top();
}