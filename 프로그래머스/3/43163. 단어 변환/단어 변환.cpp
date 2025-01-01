#include <bits/stdc++.h>

using namespace std;

bool isChange(const string &src, const string &dst) {
    if(src.size() != dst.size()) return false;
    int diff{};
    for(size_t i = 0; i < src.size(); i++) {
        if(src[i] == dst[i]) continue;
        diff++;
    }
    return diff == 1;
}

unordered_map<string, int> d;

int solution(string begin, string target, vector<string> words) {
    d[begin] = 0;
    queue<string> q;
    q.push(begin);
    while(q.size()) {
        auto cur = q.front(); q.pop();
        for(auto &nxt : words) {
            if(!isChange(cur, nxt)) continue;
            if(d.find(nxt) == d.end() || d[nxt] > d[cur] + 1) {
                d[nxt] = d[cur] + 1;
                q.push(nxt);
            }
        }
    }
    
    return (d.find(target) == d.end() ? 0 : d[target]);
}