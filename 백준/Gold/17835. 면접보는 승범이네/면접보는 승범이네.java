// Authored by : chjh2129
import java.io.*;
import java.util.*;
/*
  각 도시에서 면접장으로 가는 거리를 구하면 TLE,

  반대로 면접장에서 각 도시로 가는 거리를 구하는 방법을 채택

  간선 정보의 방향을 거꾸로 저장한 다음, 면접장이 배치된 도시를 우선순위 큐에 모두 넣고 다익스트라 진행
 */
public class Main {
  
  /*
    간선 정보 등을 배열로 간결하게 정의하는걸 선호하지만, 가중치가 int 범위를 벗어나는 경우가 있음.
    
    간선 정보를 배열로 선언하려면 long 배열로 간선을 정의해야한다. 하지만 배열의 인덱스로 long 타입 변수를 사용할 수 없다.

    long 배열을 사용하면 번거롭게 캐스팅을 계속 해줘야하므로 간결하게 객체를 정의
  */
  static class Pair{
    long w;
    int x;
    public Pair(long w, int x){ 
      this.w = w; 
      this.x = x;
    }
  }

  static final long INF = (long)1e10 + 10;

  static PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Long.compare(a.w, b.w));

  static int n, m, k;
  static long[] d;
  static List<List<Pair>> adj = new ArrayList<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());

    // 거리 배열 INF로 초기화
    d = new long[n+1];
    Arrays.fill(d, INF);

    // 인접 리스트 초기화
    for(int i = 0; i <= n; i++){
      adj.add(new ArrayList<>());
    }

    // 간선 정보 mapping
    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      long w = Integer.parseInt(st.nextToken());
      
      adj.get(v).add(new Pair(w, u));
    }

    // 면접장 배치된 도시 우선순위 큐에 삽입
    st = new StringTokenizer(br.readLine());
    while(k-- > 0){
      int x = Integer.parseInt(st.nextToken());

      d[x] = 0;
      pq.add(new Pair(0, x));
    }

    // solve
    while(!pq.isEmpty()){
      var cur = pq.poll();

      if(d[cur.x] != cur.w) continue;

      for(var nxt : adj.get(cur.x)){
        if(d[nxt.x] <= d[cur.x] + nxt.w) continue;

        d[nxt.x] = d[cur.x] + nxt.w;
        pq.add(new Pair(d[nxt.x], nxt.x));
      }
    }

    int ans = 1;
    for(int i = 2; i <= n; i++){
      if(d[ans] >= d[i]) continue;
      ans = i;
    }
    sb.append(ans+"\n"+d[ans]);

    // output
    System.out.println(sb.toString());
  }
}