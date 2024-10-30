// Authored by : chjh2129
import java.io.*;
import java.util.*;

public class Main {

  static final int INF = 0x3f3f3f3f;

  static int n, m, x;
  static int[][] d;

  // 인접 리스트, (가중치, 정점번호)를 배열로 관리(코드 작성 시간 단축)
  static List<List<int[]>> adj = new ArrayList<>();

  // 우선순위 큐, (가중치, 정점번호)를 배열로 관리(코드 작성 시간 단축)
  static PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e[0]));

  // 다익스트라를 진행할 함수 
  public static void dijkstra(int st, int[] curD){
    curD[st] = 0;
    pq.add(new int[]{curD[st], st});

    while(!pq.isEmpty()){
      var cur = pq.poll(); // var는 타입 추론 키워드(C++에서 auto와 같은 역할)

      if(curD[cur[1]] != cur[0]) continue;

      for(var nxt : adj.get(cur[1])){
        if(curD[nxt[1]] <= curD[cur[1]] + nxt[0]) continue;
        curD[nxt[1]] = curD[cur[1]] + nxt[0];
        pq.add(new int[]{curD[nxt[1]], nxt[1]});
      }
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    x = Integer.parseInt(st.nextToken());
    
    // 필요한 정보 초기화
    d = new int[n+1][n+1];
    for(int i = 0; i <= n; i++){
      adj.add(new ArrayList<>());
      Arrays.fill(d[i], INF); // 배열 값을 모두 INF로 채움
    }

    // 간선 정보 입력
    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());
      adj.get(u).add(new int[]{w, v});
    }

    // 각 정점마다 다익스트라 진행
    for(int i = 1; i <= n; i++){
      dijkstra(i, d[i]);
    }

    // 최대값 찾기
    int ans = 0;
    for(int i = 1; i <= n; i++){
      ans = Math.max(ans, d[i][x] + d[x][i]);
    }

    // 출력
    System.out.println(ans);
  } 
}