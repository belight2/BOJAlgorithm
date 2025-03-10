// Authored by : chjh212
import java.io.*;
import java.util.*;

public class Main {
  static int N, M;
  static PriorityQueue<Integer> pq = new PriorityQueue<>();
  static List<List<Integer>> adj = new ArrayList<>();
  static int[] deg;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input & init
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    
    for(int i = 0; i <= N; i++) adj.add(new ArrayList<>());
    deg = new int[N+1];
    
    while(M-- > 0){
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());

      adj.get(u).add(v);
      deg[v]++;
    }

    // topological sort
    for(int i = 1; i <= N; i++){
      if(deg[i] == 0){
        pq.add(i);
      }
    }

    while(!pq.isEmpty()){
      var cur = pq.poll();
      
      sb.append(cur+" ");
      
      for(var nxt : adj.get(cur)){
        deg[nxt]--;
        if(deg[nxt] == 0) pq.add(nxt);
      }
    }

    // output
    System.out.println(sb.toString());
  }
}