// Authored by : chjh2129
import java.io.*;
import java.util.*;

public class Main {

  static int n, m;
  static long[] tree;

  public static void update(int p, long val){
    p += n;
    tree[p] = val;
    for(int i = p; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
  }

  public static long sumQuery(int l, int r){
    long ret = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
      if((l & 1) == 1) ret += tree[l++];
      if((r & 1) == 1) ret += tree[--r];
    }
    return ret;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    tree = new long[n * 2];
    
    st = new StringTokenizer(br.readLine());
    for(int i = 0; i < n; i++){
      tree[i + n] = Integer.parseInt(st.nextToken());
    }

    for(int i = n - 1; i > 0; i--){
      tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    // Query
    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());
      int a = Integer.parseInt(st.nextToken());
      long b = Long.parseLong(st.nextToken());

      sb.append(sumQuery(Math.min(x, y) - 1, Math.max(x, y))).append("\n");
      update(a - 1, b);
    }

    // output
    System.out.println(sb.toString());
  }
}