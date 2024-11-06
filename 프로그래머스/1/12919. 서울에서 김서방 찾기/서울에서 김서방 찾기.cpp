#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> seoul) {
    auto it = seoul.begin();
    while(it != seoul.end()){
        if(*it == "Kim") break;
        it++;
    }
    return "김서방은 "+to_string(it - seoul.begin())+"에 있다";
}