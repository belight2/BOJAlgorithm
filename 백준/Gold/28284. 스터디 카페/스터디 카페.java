// Authored by : chjh212
import java.io.*;
import java.util.*;

public class Main {

  static int n, m;
  static List<int[]> pos = new ArrayList<>();
  static long[] cost;

  public static int chk(int ps, int cs){
    if(ps == 0 && cs != 0) return 1;
    if(ps != 0 && cs == 0) return -1;
    return 0;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    cost = new long[n + 1];
    st = new StringTokenizer(br.readLine());
    for(int i = 1; i <= n; i++){
      cost[i] = Long.parseLong(st.nextToken());
    }

    while(m --> 0){
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());

      pos.add(new int[]{x, 0});
      pos.add(new int[]{y, 1});
    }

    pos.sort(Comparator.comparing((int[] e) -> e[0]).thenComparing(e -> e[1]));
    Arrays.sort(cost);
    
    for(int i = 1; i <= n; i++) cost[i] += cost[i-1];
    
    // solve
    long mn = 0, mx = 0;
    int cnt = 1;
    for(int i = 1; i < pos.size(); i++){
      int px = pos.get(i-1)[0], ps = pos.get(i-1)[1];
      int cx = pos.get(i)[0], cs = pos.get(i)[1];

      long diff = cx - px + chk(ps, cs);

      mx += (cost[n] - cost[n - cnt]) * diff;
      mn += cost[cnt] * diff;

      cnt += (cs > 0 ? -1 : 1);
    }
    
    // output
    sb.append(mn).append(" ").append(mx);
    System.out.println(sb.toString());
  }
}