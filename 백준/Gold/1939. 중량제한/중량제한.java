import java.io.*;
import java.util.*;
public class Main {
  
  static int N, M;
  static int[] P;
  static List<int[]> Edges = new ArrayList<>();

  public static int swap(int x, int y){ return x; }

  public static int find(int x){
    if(P[x] < 0) return x;
    return P[x] = find(P[x]);
  }
  
  public static void union(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(P[x] == P[y]) P[x]--;
    if(P[x] > P[y]) x = swap(y, y = x);
    P[y] = x;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
        
    // 간선 정보
    for(int i = 0; i < M; i++){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());
      Edges.add(new int[]{w, u, v});
    }

    // 출발지와 목적지 입력 받기
    st = new StringTokenizer(br.readLine());
    int start = Integer.parseInt(st.nextToken());
    int end = Integer.parseInt(st.nextToken());

    // 간선 정보를 가중치를 기준으로 내림차순 정렬
    Edges.sort(new Comparator<int[]>() {
      @Override
      public int compare(int[] e1, int[] e2){
        return Integer.compare(e2[0], e1[0]);
      }
    });

    // init
    P = new int[N+1];
    for(int i = 0; i <= N; i++) P[i] = -1;

    // solve
    for(int[] cur : Edges){
      union(cur[1], cur[2]);
      if(find(start) == find(end)){
        sb.append(cur[0]);
        break;
      }
    }

    // output
    System.out.println(sb.toString());
  }  
}