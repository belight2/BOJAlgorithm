#include <string>
#include <vector>

using namespace std;

string solution(string pn) {
    int sz = pn.size() - 4;
    for(int i = 0; i < sz; i++) pn[i] = '*';
    return pn;
}