// Authored by : chjh2129
import java.io.*;
import java.util.*;
/*
  양의 사이클이 존재하면서 그 양의 사이클에서 도착지로 이동이 가능한지 판별해야하는 문제 

  간선 방향을 역방향으로 따로 저장해 n을 출발지로 dfs로 전처리하여 해결할 수 있음.

  경로를 추적하는 방법은 테이블이 갱신될 때, prv로 따로 갱신해 처리

  물론, 1번에서 n으로 도달할 수 없는 경우도 -1를 출력해야 함.
*/
public class Main {
  
  static final int INF = -(int)1e8; // 음수 infinity

  static int n, m;

  // 간선의 방향을 역으로 저장하는 인접리스트
  static List<List<Integer>> adj = new ArrayList<>();

  // 방문 배열
  static boolean[] vis;

  // 간선 정보
  static List<int[]> edges = new ArrayList<>();

  static int[] d; // 거리 테이블

  static int[] prv; // prv[i] : i정점에 최대한 많은 금품을 가진채로 도착하기 위해서 직전에 들려야하는 정점의 정보

  /*
    n에서 출발해서 방문할 수 있는 정점의 정보를 매핑
  */
  static void dfs(int cur){
    vis[cur] = true;
    for(var nxt : adj.get(cur)){
      if(vis[nxt]) continue;
      dfs(nxt);
    }
  }
  /*
    벨만-포드를 진행, 거리 테이블을 최대값으로 세팅
    
    n-th 완화에서 갱신이 되었을 때, n번 정점으로 도착이 가능하다면 false를 반환
  */
  static boolean bellmanFord(){
    Arrays.fill(d, INF);

    d[1] = 0;
    for(int i = 1; i <= n; i++){
      for(var cur : edges){
        int u = cur[0], v = cur[1], w = cur[2];
        
        if(d[u] == INF || d[u] + w <= d[v]) continue;

        d[v] = d[u] + w;
        prv[v] = u; // 경로 추적을 위한 갱신

        if(i == n && vis[v]) return false;
      }
    }
    return true;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    d = new int[n+1];
    prv = new int[n+1];
    vis = new boolean[n+1];

    for(int i = 0; i <= n; i++){
      adj.add(new ArrayList<>());
    }

    // 간선 정보 mapping
    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());

      edges.add(new int[]{u, v, w});
      adj.get(v).add(u);
    }

    // solve
    dfs(n);

    // 1번에서 n번으로 이동 불가 또는 양의 사이클에서 n번으로 이동 가능한 경우
    // -1 출력 후 종료
    if(!vis[1] || !bellmanFord()){
      System.out.println(-1);
      System.exit(0);
    }

    // 경로 추적
    List<Integer> path = new ArrayList<>();
    while(n != 1){
      path.add(n);
      n = prv[n];
    }
    path.add(1);
    Collections.reverse(path);
    path.stream().forEach(e -> sb.append(e + " "));


    // output
    System.out.println(sb.toString());
  }
}