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
  public static ArrayList<ArrayList<int[]>> adj = new ArrayList<>();
  public static boolean[] chk;
  public static PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e[0]));

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    t = Integer.parseInt(st.nextToken());
    
    for(int i = 0; i <= n; i++) adj.add(new ArrayList<>());
    chk = new boolean[n+1];
    
    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());
      adj.get(u).add(new int[]{w, v});
      adj.get(v).add(new int[]{w, u});
    }

    // solve
    chk[1] = true;
    for(int[] nxt : adj.get(1)) pq.add(new int[]{nxt[0], 1, nxt[1]});

    long ans = 0, cnt = 0;
    while(cnt < n - 1){
      int[] cur = pq.poll();
      if(chk[cur[2]]) continue;
      chk[cur[2]] = true;
      ans += cur[0];
      cnt++;
      
      for(int[] nxt : adj.get(cur[2])){
        if(chk[nxt[1]]) continue;
        pq.add(new int[]{nxt[0], cur[2], nxt[1]});
      }
    }

    // cnt값 조정
    cnt = (n-1) * (n-2) / 2;

    // output
    System.out.println(ans + cnt * t);
  }
}