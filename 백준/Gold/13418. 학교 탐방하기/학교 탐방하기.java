import java.io.*;
import java.util.*;
/*
  최소 신장 트리와 최대 신장 트리의 가중치 합을 각각 구해
  
  서로 제곱한 값의 차를 구하는 문제입니다.

  정점의 개수는 0번부터 n번까지 총 n+1개 있습니다. 이를 유의하세요. 
 */
public class Main {

  public static int n, m;
  public static ArrayList<int[]> edge = new ArrayList<>();
  public static int[] p;

  public static int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  public static boolean union(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(p[x] == p[y]) p[x]--;
    if(p[x] > p[y]) p[x] = y;
    else p[y] = x;
    return true;
  }

  public static int solve(boolean flag){
    if(flag) edge.sort((e1, e2) -> Integer.compare(e2[0], e1[0]));
    else edge.sort(Comparator.comparingInt(e -> e[0]));

    for(int i = 0; i <= n; i++) p[i] = -1;

    int sum = 0, cnt = 0;
    for(int[] cur : edge){
      if(!union(cur[1], cur[2])) continue;
      cnt++;
      sum += cur[0];
      if(cnt == n) break;
    }

    return sum * sum;
  }
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    p = new int[n+1];
    for(int i = 0; i <= n; i++) p[i] = -1;
    
    while(m-- >= 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());
      edge.add(new int[]{w^1, u, v});
    }
    
    // solve
    sb.append(solve(true) - solve(false));

    // output
    System.out.println(sb.toString());
  }
  
}