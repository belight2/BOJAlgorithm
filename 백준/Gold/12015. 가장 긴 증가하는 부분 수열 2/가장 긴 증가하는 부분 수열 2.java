// Authored by : chjh2129
import java.io.*;
import java.util.*;
/*
  배열 정보를 {x, i}로 저장합니다. x는 배열의 값이고 i는 index 정보입니다.

  아래와 같이 x는 오름차순, i는 내림차순이되게 정렬합니다.

  {1, 3}
  {1, 2}
  {1, 1}
  {2, 4}

  세그먼트 트리는 LIS의 길이 정보를 저장하게 합니다. 초기에 모든 리프 노드 값이 0입니다.

  정렬한 배열은 순차 탐색하면서 [0, i] 범위에서 LIS의 최대 길이를 구합니다.

  이렇게 구한 LIS 길이에 +1한 값으로 세그먼트 트리를 갱신합니다.

  이를 모두 완료했다면 세그먼트 트리의 루트 값이 입력으로 주어진 배열의 LIS 길이가 됩니다.
*/
public class Main {
  
  static int n;
  static int[] tree;
  static List<int[]> a = new ArrayList<>();

  public static void update(int p, int val){
    p += n;
    tree[p] = val;
    for(int i = p; i > 1; i >>= 1) tree[i >> 1] = Math.max(tree[i], tree[i ^ 1]);
  }

  public static int maxQuery(int l, int r){
    int ret = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
      if((l & 1) == 1) ret = Math.max(ret, tree[l++]);
      if((r & 1) == 1) ret = Math.max(ret, tree[--r]);
    }
    return ret;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;

    // input
    n = Integer.parseInt(br.readLine());
         
    st = new StringTokenizer(br.readLine());
    for(int i = 0; i < n; i++){
      a.add(new int[]{Integer.parseInt(st.nextToken()), i});
    }

    // init
    tree = new int[n * 2];

    Collections.sort(a, (x, y) -> {
      if(x[0] == y[0]){
        return Integer.compare(y[1], x[1]);
      }
      return Integer.compare(x[0], y[0]);
    });

    // Query
    for(var cur : a){
      int mx = maxQuery(0, cur[1]) + 1;
      update(cur[1], mx);
    }

    // output
    System.out.println(tree[1]);
  }  
}