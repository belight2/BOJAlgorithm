import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
  parent 배열을 -1로 초기화한다.(노드 번호 x에 대해서 p[x] < 0일 때, x가 루트 노드)

  rank는 union이 된 횟수를 기준으로 평가함, rank가 큰 집합이 자식 노드가 많음

  rank가 작은 집합을 rank가 큰 집합으로 union 하는 것이 union by rank임.
 */
public class Main {
  
  static int n, m;
  static int[] p;

  public static int swap(int x, int y){ return x; }

  public static int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  // parent 배열이 음수이므로 작을수록 큰 rank임
  public static void union(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(p[x] == p[y]) p[x]--; // 두 집합의 rank가 같다면 집합 하나를 임의로 rank 증가
    if(p[x] > p[y]) x = swap(y, y = x); // y 집합을 x에 union하기 위해 y의 rank가 더 크다면 swap

    p[y] = x;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());
  
    // input
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    // init
    p = new int[n+1];
    for(int i = 0; i <= n; i++) p[i] = -1;

    // solve
    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int q = Integer.parseInt(st.nextToken());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());

      if(q == 0) union(u, v);
      else if(find(u) == find(v)) sb.append("YES\n");
      else sb.append("NO\n");
    }

    // output
    System.out.println(sb.toString());
  }
}