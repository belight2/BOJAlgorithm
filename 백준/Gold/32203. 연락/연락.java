import java.io.*;
import java.util.*;

public class Main {
  public static int N, M;
  public static long[][] cnt;
  public static int[] p;
  public static long ans;

  public static int swap(int x, int y){ return x; }

  public static int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  public static void union(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(p[x] == p[y]) p[x]--;
    if(p[x] > p[y]) x = swap(y, y = x);

    ans -= cnt[x][0] * cnt[x][1] + cnt[y][0] * cnt[y][1];
    cnt[x][0] += cnt[y][0];
    cnt[x][1] += cnt[y][1];
    ans += cnt[x][0] * cnt[x][1];

    p[y] = x;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input 1
    N = Integer.parseInt(st.nextToken()); 
    M = Integer.parseInt(st.nextToken());

    // init
    cnt = new long[N+1][2];
    p = new int[N+1];
    for(int i = 0; i <= N; i++) p[i] = -1;

    // input 2
    st = new StringTokenizer(br.readLine());
    for(int cur = 1; cur <= N; cur++){
      int G = Integer.parseInt(st.nextToken());
      if(G % 2 == 0) cnt[cur][0]++;
      else cnt[cur][1]++;
    }

    // solve
    while(M-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      union(u, v);
      sb.append(ans+"\n"); 
    }

    // output
    System.out.println(sb.toString());
  }
}