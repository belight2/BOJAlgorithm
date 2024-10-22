import java.io.*;

/*
  g가 주어졌을 때, 1번부터 g번 중 아직 도킹하지 않은 게이트를 찾는 쿼리를 최적화하는 것이 핵심인 문제

  idx[x] = x를 가지게 한 다음, 좌표 압축을 응용하여 도킹할 게이트를 찾는 쿼리를 최적화할 수 있습니다.

  idx[x] = x인 값을 찾으면 아직 도킹하지 않은 게이트 번호를 찾았다고 할 수 있습니다.

  도킹을 했다면 idx[x]의 값을 1 감소하여 x-1로 갱신하여 idx[x-1]에서 도킹할 게이트 번호를 찾도록 구현합니다.

  찾은 번호가 0이라면 더 이상 도킹이 불가능하다고 판단할 수 있습니다. 
 */
public class Main {
  
  public static int n, m;
  public static int[] idx;

  public static int find(int x){
    if(idx[x] == x) return x;
    return idx[x] = find(idx[x]);
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    // input
    n = Integer.parseInt(br.readLine());
    m = Integer.parseInt(br.readLine());

    // init
    idx = new int[n+1];
    for(int i = 0; i <= n; i++) idx[i] = i;

    // solve
    int ans = 0, g;
    while(m-- > 0){
      g = Integer.parseInt(br.readLine());
      g = find(g);
      if(g == 0) break;
      idx[g]--;
      ans++;
    }

    // output
    System.out.println(ans);
  }
  
}