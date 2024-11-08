#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string ans{};
    ans.push_back(s[s.size() / 2]);
    if(s.size() % 2 == 0) ans.push_back(s[s.size() / 2 - 1]);
    reverse(ans.begin(), ans.end());
    return ans;
}