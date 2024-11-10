// Authored by : chjh2129
import java.io.*;
import java.util.*;
/*
  < 초기화 방법 >
  DVD 개수 n과 쿼리 수행 횟수 m이 주어졌을 때, n + m 크기로 배열로 세그먼트 트리를 구성합니다.
  크기가 n+m인 배열은 범위에 따라 아래와 같이 초기화합니다
 
  [0, n-1] : 1, DVD가 있는 곳
  [n, n+m) : 0, DVD가 없는 곳

  번호가 거꾸로 쌓여있으므로 번호에 따라 위치 정보를 알려주는 idx 배열을 선언합니다.

  idx[x] = 0, x번 DVD의 위치가 현재 0임  

  세그먼트 트리를 각 테스트케이스마다 새로 구성해야 함. 
  이 부분이 중요한 것도 아닌데 까다로워서 그냥 class로 만들어서 사용함.
  (Java는 클래스 구현없이 진행함. C++만 세그먼트 클래스로 구현)
  ----------------------------------------  
 
  < 풀이하는 방법 >
  
  각 쿼리마다, x번 dvd를 위에 올려야합니다. 
  
  int new_pos = n;

  idx[x]의 위치를 new_pos로 갱신해줍니다. 
  x번 보다 위에 있는 dvd 개수를 세기 위해서는 세그먼트 트리에서 (idx[x] + 1, MAX)을 범위로 합 쿼리를 수행하면 됩니다.
*/
public class Main {

  static int n, m;
  static long[] tree;
  static List<Integer> idx;

  static void update(int p, long val){
    p += n+m;
    tree[p] = val;
    for(int i = p; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
  }

  static long sumQuery(int l, int r){
    long ret = 0;
    for(l += n + m, r += n + m; l < r; l >>= 1, r >>= 1){
      if((l & 1) == 1) ret += tree[l++];
      if((r & 1) == 1) ret += tree[--r];
    }
    return ret;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;
    
    int t = Integer.parseInt(br.readLine());
    while(t-- > 0){
      idx = new ArrayList<>();
      // input & init
      st = new StringTokenizer(br.readLine());
      n = Integer.parseInt(st.nextToken());
      m = Integer.parseInt(st.nextToken());

      for(int i = n; i >= 0; i--) idx.add(i);

      tree = new long[2 * (n + m)];
      for(int i = 0; i < n; i++) tree[i + n + m] = 1;
      for(int i = n + m - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];
       
      // Query
      st = new StringTokenizer(br.readLine());
      int npos = n;
      for(int i = 0; i < m; i++){
        int x = Integer.parseInt(st.nextToken());
        
        sb.append(sumQuery(idx.get(x)+1, n+m)).append(" ");

        update(idx.get(x), 0L);
        idx.set(x, npos++);
        update(idx.get(x), 1L);
      }      
      sb.append("\n"); 
    }

    // output
    System.out.println(sb.toString());
  }
}