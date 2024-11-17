// Authored by : chjh2129
import java.io.*;
import java.util.*;

public class Main {

  static int n, l;
  static List<int[]> a = new ArrayList<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    n = Integer.parseInt(st.nextToken());
    l = Integer.parseInt(st.nextToken());
    
    for(int i = 0; i < n; i++){
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());

      a.add(new int[]{x, y});
    }

    // solve
    a.sort(Comparator.comparing((int[] e) -> e[0]).thenComparing(e -> e[1]));

    int ans = 0;
    int tx = a.get(0)[0] - 1;
    for(int i = 0; i < n; i++){
      if(tx >= a.get(i)[1]) continue;

      int cx = (tx < a.get(i)[0] ? a.get(i)[0] : tx + 1);
      int len = a.get(i)[1] - cx;
      int q = len / l + (len % l != 0 ? 1 : 0);

      ans += q;
      tx = cx + q * l - 1;
    } 

    // output
    System.out.println(ans);
  }
}