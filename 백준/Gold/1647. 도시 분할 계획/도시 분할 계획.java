import java.io.*;
import java.util.*;

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

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    // input & init
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    p = new int[n+1];
    for(int i = 0; i <= n; i++) p[i] = -1;

    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int cost = Integer.parseInt(st.nextToken());
      edge.add(new int[]{cost, u, v});   
    }

    // solve
    edge.sort(Comparator.comparingInt(e -> e[0]));
    int Town = n, ans = 0;
    for(int[] cur : edge){
      if(Town == 2) break;
      if(!union(cur[1], cur[2])) continue;
      Town--;
      ans += cur[0];
    }

    // output
    System.out.println(ans);
  }
}