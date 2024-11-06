// Authored by : chjh2129
#include <bits/stdc++.h>
/*
  증가하는 부분 수열은 오름차순으로 정렬되어 있습니다.

  이러한 특성을 이용하여 이분 탐색(lower_bound)으로 문제를 풀이할 수 있습니다.

  수열을 순회하면서 각 값이 LIS에서 어디에 위치할 수 있는지 lower_bound로 검사합니다.

  idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();

  위와 연산은 다음을 의미합니다.
  
  i) lis에서 a[i]가 있다.
  
      1. lis[idx] = a[i]인 idx값을 가집니다.

  ii) lis에서 a[i]가 없다.

      2. a[i]보다 큰 값 중 가장 작은 값의 위치 값을 가집니다. (lis[idx] > a[i])

      3. a[i]보다 큰 값이 없다면 idx는 lis.size()의 값을 가집니다.

  1번과 2번의 경우 lis[idx] = a[i]로 갱신합니다.

  3번인 경우 : lis.push_back(a[i])를 수행합니다.

  순회가 끝나면 lis의 크기는 LIS의 길이 정보를 가집니다.
*/
using namespace std;

int n;
int a[1'000'005];
vector<int> lis;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  // solve
  for(int i = 0; i < n; i++){
    int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();

    if(idx == lis.size()) lis.push_back(a[i]);
    else lis[idx] = a[i];
  }

  // output
  cout << lis.size();
}