// Authored by : chjh2129
import java.io.*;
import java.util.*;
public class Main {
  
  static int n, m;
  static long[] tree;

  public static void modify(int p, long val){
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

    // Query
    while(m -- > 0){
      st = new StringTokenizer(br.readLine());
      int cmd = Integer.parseInt(st.nextToken());
      int a = Integer.parseInt(st.nextToken());
      long b = Long.parseLong(st.nextToken());

      if(cmd == 1) modify(a-1, b);
      else sb.append(sumQuery(Math.min(a, (int)b)-1, Math.max(a, (int)b)) + "\n");
    }

    // output
    System.out.println(sb.toString());
  }
}