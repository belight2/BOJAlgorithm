#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p{}, y{};
    for(char c : s){
        if(tolower(c) == 'y') y++;
        if(tolower(c) == 'p') p++;
    }
    return p == y;
}