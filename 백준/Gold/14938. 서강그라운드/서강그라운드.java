// Authored by : chjh2129
import java.io.*;
import java.util.*;

public class Main {

  static final int INF = 0x300000;

  static int n, m, r;

  static int[][] d;

  static int[] item;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    r = Integer.parseInt(st.nextToken());

    d = new int[n+1][n+1];
    item = new int[n+1];
    
    st = new StringTokenizer(br.readLine());
    for(int i = 1; i <= n; i++){
      item[i] = Integer.parseInt(st.nextToken());
      Arrays.fill(d[i], INF);
    }

    while(r-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());

      d[u][v] = w;
      d[v][u] = w;
    }

    // solve
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    
    // 플로이드-와샬 알고리즘
    for(int k = 1; k <= n; k++){
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
          d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }

    // 답 구하기
    int ans = 0;
    for(int i = 1; i <= n; i++){
      int tmp = 0;

      // i -> j로 m 이하로 이동할 수 있다면, item[j]를 획득할 수 있음.
      for(int j = 1; j <= n; j++){
        if(d[i][j] > m) continue;
        tmp += item[j];
      }

      ans = Math.max(ans, tmp);
    }

    // output
    System.out.println(ans);
  }
}