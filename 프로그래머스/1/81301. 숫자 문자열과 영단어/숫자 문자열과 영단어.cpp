#include <bits/stdc++.h>

using namespace std;

unordered_map<string, char> convert = {
    {"zero", '0'}, {"one", '1'},
    {"two", '2'}, {"three", '3'},
    {"four", '4'}, {"five", '5'},
    {"six", '6'}, {"seven", '7'},
    {"eight", '8'}, {"nine", '9'}
};

int solution(string s) {
    string ans{}, number{};
    
    for(char c : s){
        if(isdigit(c)){
            ans.push_back(c);
            continue;
        }
        number.push_back(c);
        if(convert.find(number) == convert.end()) continue;
        ans.push_back(convert[number]);
        number = "";
    }

    return stoi(ans);
}