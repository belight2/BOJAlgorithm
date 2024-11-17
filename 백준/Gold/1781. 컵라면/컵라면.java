// Authored by : chjh2129
import java.io.*;
import java.util.*;

public class Main {

  static int n;
  static PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
  static List<List<Integer>> dead_line = new ArrayList<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;

    // input & init
    n = Integer.parseInt(br.readLine());
    
    for(int i = 0; i <= n; i++) dead_line.add(new ArrayList<>());

    for(int i = 0; i < n; i++){
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());
      dead_line.get(x).add(y);
    }

    // solve
    /*
      모든 문제는 풀이하는데 단위 시간 1이 걸린다.
      데드 라인을 역순으로 우선순위 큐에 문제 당 컵라면 개수를 삽입하여
      데드 라인 전에 풀었을 때, 가장 많이 받을 수 있는 컵라면의 개수를 알 수 있다.
    */
    int ans = 0;
    for(int cur = n; cur > 0; cur--){
      for(int noodle : dead_line.get(cur)) pq.add(noodle);
      if(pq.isEmpty()) continue;

      ans += pq.poll();
    }

    // output
    System.out.println(ans);
  }
}