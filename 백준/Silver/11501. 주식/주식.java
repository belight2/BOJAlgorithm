// Authored by : chjh2129
import java.io.*;
import java.util.*;

public class Main {

  static int n;
  static Stack<Integer> stk = new Stack<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;

    int t = Integer.parseInt(br.readLine());
    while(t --> 0){
      // input & init
      n = Integer.parseInt(br.readLine());
      st = new StringTokenizer(br.readLine());
      
      while(st.hasMoreTokens()){
        stk.add(Integer.parseInt(st.nextToken()));
      }

      // solve
      long ans = 0;
      int mx = stk.peek();
      while(!stk.isEmpty()){
        int cur = stk.pop();
        if(cur < mx) ans += mx - cur;
        else mx = cur;
      }

      // StringBuilder mapping
      sb.append(ans).append("\n");
    }

    // output
    System.out.println(sb.toString());
  }
}