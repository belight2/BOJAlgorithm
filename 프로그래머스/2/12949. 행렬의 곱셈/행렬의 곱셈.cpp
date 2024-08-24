#include <string>
#include <vector>

using namespace std;

int arow, acol, brow, bcol;

vector<vector<int>> solution(vector<vector<int>> a, vector<vector<int>> b) {
    arow = a.size();
    acol = brow = b.size();
    bcol = b[0].size();
    vector<vector<int>> ans(arow, vector<int>(bcol));
    
    for(int k = 0; k < acol; k++){
        for(int i = 0; i < arow; i++){
            for(int j = 0; j < bcol; j++){
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}