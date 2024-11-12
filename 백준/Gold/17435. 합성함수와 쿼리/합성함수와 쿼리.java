// Authored by : chjh2129
import java.io.*;
import java.util.*;

public class Main {

  static int n;
  static int[][] nxt;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;
    // input & init
    n = Integer.parseInt(br.readLine());

    nxt = new int[31][n+1];

    st = new StringTokenizer(br.readLine());
    for(int i = 1; i <= n; i++){
      nxt[0][i] = Integer.parseInt(st.nextToken());
    }

    for(int k = 1; k <= 30; k++){
      for(int i = 1; i <= n; i++){
        nxt[k][i] = nxt[k-1][nxt[k-1][i]];
      }
    }

    // solve
    int q = Integer.parseInt(br.readLine());
    while(q-- > 0){
      st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      int x = Integer.parseInt(st.nextToken());

      for(int i = 30; i >= 0; i--){
        if((n & (1 << i)) != 0){
          x = nxt[i][x];       
        }
      }

      sb.append(x).append("\n");
    }

    // output
    System.out.println(sb.toString());
  }
}