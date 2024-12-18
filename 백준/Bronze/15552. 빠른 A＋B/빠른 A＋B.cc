#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int t, limit, i, a, b, c, d;
    cin >> t;

    limit = t - 1;
    for(i = 0; i < limit; i += 2) {
        cin >> a >> b >> c >> d;
        
        cout << a + b << '\n' << c + d << '\n';
    }

    for(; i < t; i++) {
        cin >> a >> b;
        cout << a + b << '\n';
    }
}