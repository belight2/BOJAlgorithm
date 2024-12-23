import java.io.*;
import java.util.*;
/*
  미리 연결되어 있는 정점들은 가중치가 0인 간선을 추가로 인접리스트에 추가한 다음

  프림 알고리즘을 사용하면 풀이할 수 있습니다. 
*/
public class Main {
  
  public static int n, m;
  public static int[][] pos;
  public static ArrayList<ArrayList<long[]>> adj = new ArrayList<>();
  public static boolean[] chk;
  public static PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(e -> e[0]));

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    pos = new int[n+1][2];
    chk = new boolean[n+1];
    
    for(int i = 0; i <= n; i++) adj.add(new ArrayList<>());
    
    for(int i = 1; i <= n; i++){
      st = new StringTokenizer(br.readLine());
      pos[i][0] = Integer.parseInt(st.nextToken());
      pos[i][1] = Integer.parseInt(st.nextToken());
    }

    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      adj.get(u).add(new long[]{0, v});
      adj.get(v).add(new long[]{0, u});
    }

    // solve 
    for(int i = 1; i <= n; i++){
      for(int j = i + 1; j <= n; j++){
        long dx = pos[i][0] - pos[j][0];
        long dy = pos[i][1] - pos[j][1];
        long dist = dx*dx + dy*dy;
        adj.get(i).add(new long[]{dist, j});
        adj.get(j).add(new long[]{dist, i});
      }
    }

    chk[1] = true;
    for(long[] nxt : adj.get(1)) pq.add(new long[]{nxt[0], 1, nxt[1]});

    int cnt = 0;
    double ans = 0.;
    while(cnt < n - 1){
      long[] cur = pq.poll();
      if(chk[(int)cur[2]]) continue;
      cnt++;
      chk[(int)cur[2]] = true;
      ans += Math.sqrt(cur[0]);
      
      for(long[] nxt : adj.get((int)cur[2])){
        if(chk[(int)nxt[1]]) continue;
        pq.add(new long[]{nxt[0], cur[2], nxt[1]});
      }
    }

    // output
    System.out.println(String.format("%.2f", ans));
  }
}