import java.io.*;
import java.util.*;
/*
  가상의 정점(n+1)이 하나 더 있다고 가정하게 된다면

  i번 우물을 팔 때 드는 비용을 i번과 (n+1)번을 잇는 간선의 가중치라고 생각할 수 있습니다.

  문제에서 주어진 그래프를 문제를 풀기 위해 변형하는 것을 그래프 모델링이라고 합니다.
*/

public class Main {
  
  public static int n;
  public static ArrayList<ArrayList<int[]>> adj = new ArrayList<>();
  public static boolean[] chk;
  public static PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e[0]));

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;

    // input & init
    n = Integer.parseInt(br.readLine());
    
    chk = new boolean[n+2];
    for(int i = 0; i <= n+2; i++) adj.add(new ArrayList<>());

    for(int cur = 1; cur <= n; cur++){
      int cost = Integer.parseInt(br.readLine());
      adj.get(cur).add(new int[]{cost, n+1});
      adj.get(n+1).add(new int[]{cost, cur});
    }

    for(int i = 1; i <= n; i++){
      st = new StringTokenizer(br.readLine());
      for(int j = 1; j <= n; j++){
        int cost = Integer.parseInt(st.nextToken());
        if(i >= j) continue;
        adj.get(i).add(new int[]{cost, j});
        adj.get(j).add(new int[]{cost, i});
      }
    }

    // solve
    chk[1] = true;
    for(int[] cur : adj.get(1)) pq.add(new int[]{cur[0], 1, cur[1]});

    int cnt = 0, ans = 0;
    while(cnt < n){
      int[] cur = pq.poll();
      if(chk[cur[2]]) continue;
      cnt++;
      ans += cur[0];
      chk[cur[2]] = true;
      
      for(int[] nxt : adj.get(cur[2])){
        if(chk[nxt[1]]) continue;
        pq.add(new int[]{nxt[0], cur[2], nxt[1]});
      }
    }

    // output
    System.out.println(ans);
  }
  
}