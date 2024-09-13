// Authored by : chjh2129
/*
  각각의 우주에 대해서 좌표 압축을 진행한다.
  문제의 조건 만족한다면 압축된 두 우주는 서로 같은 원소값을 가진다.
*/
#include <bits/stdc++.h>

using namespace std;

int m, n;
int universe[105][10'005];

// 매개변수로 배열을 전달하면, 주소값이 전달됩니다.
void compress(int a[]){
  vector<int> v(a, a+n); // 배열의 a[0]값부터 a[n-1]까지를 원소로하는 벡터를 생성
  
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end()); // 중복 값을 제거한다.

  // 좌표 압축 진행
  for(int i = 0; i < n; i++){
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
  }
}

// 우주 a와 b가 균등한지 비교한다.
bool compare(int a[], int b[]){
  for(int i = 0; i < n; i++){
    if(a[i] != b[i]) return 0;
  }
  return 1;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> m >> n;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> universe[i][j];
    }
    compress(universe[i]); // i번째 우주를 좌표 압축한다.
  }

  // solve
  int ans{};
  for(int i = 0; i < m-1; i++){
    for(int j = i+1; j < m; j++){
      ans += compare(universe[i], universe[j]);
    }
  }

  // output
  cout << ans;
}