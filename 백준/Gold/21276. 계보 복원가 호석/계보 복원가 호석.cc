#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const char nl = '\n';
int n, m;
string a, b;
vector<int> adj[1001];
vector<int> tree[1001];
int deg[1001];
unordered_map<string, int> idx;
unordered_map<int, string> name;

vector<string> root;
vector<string> res;
void topological_sort(){
  queue<int> q;
  for(int i = 1; i <= n; i++) if(!deg[i]){
    q.push(i);
    root.push_back(name[i]);
  }
  while(!q.empty()){
    int cur = q.front(); q.pop();
    res.push_back(name[cur]);
    for(int nxt : adj[cur]){
      if(--deg[nxt] == 0){
        tree[cur].push_back(nxt);
        q.push(nxt);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a;
    idx[a] = i;
    name[i] = a;
  }
  cin >> m;
  while(m--){
    cin >> a >> b;
    adj[idx[b]].push_back(idx[a]);
    deg[idx[a]]++;
  }
  topological_sort();
  // print
  sort(root.begin(), root.end());
  sort(res.begin(), res.end());
  cout << root.size() << nl;
  for(string a : root) cout << a << ' ';
  for(string a : res){
    cout << nl;
    vector<string> child;
    for(int c : tree[idx[a]]) child.push_back(name[c]);
    sort(child.begin(), child.end());
    cout << a << ' ' << child.size() << ' ';
    for(string c : child) cout << c << ' ';
  }
  
}