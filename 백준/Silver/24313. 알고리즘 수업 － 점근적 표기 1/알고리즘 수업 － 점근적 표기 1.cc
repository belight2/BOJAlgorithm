#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int f = n * a + b;
    int g = n;
    cout << (f <= c * g && a <= c);
}