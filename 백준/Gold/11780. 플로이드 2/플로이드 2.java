// Authored by : chjh2129
import java.io.*;
import java.util.*;
public class Main {

  static final int INF = 0x3f3f3f3f;

  static int n, m;
  
  // nxt[a][b] = c, 정점 a에서 정점 b의 최단 경로가 a -> c -> ... b임을 의미함
  static int[][] d, nxt;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;

    // input & init
    n = Integer.parseInt(br.readLine());
    m = Integer.parseInt(br.readLine());

    d = new int[n+1][n+1];
    nxt = new int[n+1][n+1];
    
    // 인접 행렬 초기화
    for(int i = 1; i <= n; i++) Arrays.fill(d[i], INF);

    // 간선
    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());

      // u -> v 간선이 여러 개 있을 수 있으므로 그 중 가중치가 최소인 것만 저장
      d[u][v] = Math.min(d[u][v], w);

      nxt[u][v] = v; // 경로 추적 배열 초기화
    }

    // solve
    // 인접 행렬 초기화
    for(int i = 1; i <= n; i++) d[i][i] = 0;

    // 플로이드-와샬
    for(int k = 1; k <= n; k++){
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
          if(d[i][k] + d[k][j] < d[i][j]){
            d[i][j] = d[i][k] + d[k][j];

            nxt[i][j] = nxt[i][k]; // 경로 추적 배열 갱신
          }
        }
      }
    }

    // String Builder에 mapping
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(d[i][j] == INF) d[i][j] = 0;
        sb.append(d[i][j] + " ");
      }
      sb.append("\n");
    }

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(d[i][j] == 0){
          sb.append("0\n");
          continue;
        }
        
        // 경로 추적
        List<Integer> path = new ArrayList<>();
        int src = i;
        while(src != j){
          path.add(src);
          src = nxt[src][j];
        }
        path.add(j);

        sb.append(path.size()+" ");
        path.stream().forEach(e -> sb.append(e + " "));
        sb.append("\n");
      }
    }

    // output
    System.out.println(sb.toString());
  }  
}