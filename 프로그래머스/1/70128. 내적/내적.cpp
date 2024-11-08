#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int ans{};
    for(int i = 0; i < a.size(); i++){
        ans += a[i] * b[i];
    }
    return ans;
}