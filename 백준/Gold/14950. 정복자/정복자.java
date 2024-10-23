import java.io.*;
import java.util.*;
/*
  무방향 가중치 연결 그래프입니다.

  정복할 때마다 t만큼 모든 도로의 비용이 증가하지만

  모든 도시를 정복해야 하므로 추가되는 비용은 정점의 개수에 비례하게 증가합니다.

  따라서 MST가 되는 간선들의 가중치의 합과 정점의 개수에 맞추어 추가 비용을 더해주시면 됩니다.
 */
public class Main {

  public static int n, m, t;
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
    t = Integer.parseInt(st.nextToken());
    
    p = new int[n+1];
    for(int i = 0; i <= n; i++) p[i] = -1;

    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());
      edge.add(new int[]{w, u, v});
    }

    // solve
    long ans = 0, cnt = 0;
    edge.sort(Comparator.comparingInt(e -> e[0]));
    for(int[] cur : edge){
      if(!union(cur[1], cur[2])) continue;
      ans += cur[0];
      cnt++;
      if(cnt == n - 1) break;
    }

    // cnt값 조정
    cnt = (n - 1) * (n - 2) / 2;

    // output
    System.out.println(ans + cnt * t);
  }
}