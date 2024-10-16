import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static int n, m;
  static int[] p;

  public static int swap(int x, int y){ return x; }

  public static int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  public static boolean union(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(p[x] == p[y]) p[x]--;
    if(p[x] > p[y]) y = swap(x, x = y);
    p[y] = x;
    return true;
  }

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    // init
    p = new int[n];
    for(int i = 0; i < n; i++) p[i] = -1;
    
    // solve
    int ans = 0;
    for(int round = 1; round <= m; round++){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      if(!union(u, v)){
        ans = round;
        break;
      }
    }

    // output
    System.out.println(ans);
  } 
}
