// Authored by : chjh2129
import java.io.*;
import java.util.*;
/*
  구간 합 세그먼트를 두 개 선언합니다.

  dist : x = 0으로부터의 거리를 저장하는 세그먼트 트리

  cnt : x에 심어진 나무의 개수

  x에 나무를 심는다고 가정하면 두 세그먼트 트리를 이용하여 나무를 심는 비용을 구할 수 있습니다.

  왼쪽에 있는 나무들의 거리 합 = dist.sumq(0, x) - cnt.sumq(0, x) * x
  오른쪽에 있는 나무들의 거리 합 = dist.sumq(x+1, MX) - cnt.sumq(x+1, MX) * x

  이 두 값을 더하면 x에 나무를 심을 때, 드는 비용을 구할 수 있습니다.

  주의할 점은 나무를 같은 위치에 여러 번 심을 수도 있고, 오버플로우도 조심해야합니다.
*/
public class Main {
  private static final long MOD = (long)1e9 + 7L;
  private static final int MX = 200005;

  static int n, x;
  static long[] cnt, dist;

  static void update(int p, long val, long[] tree){
    p += MX;
    tree[p] += val;
    for(int i = p; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
  }

  static long sumQuery(int l, int r, long[] tree){
    long ret = 0;
    for(l += MX, r += MX; l < r; l >>= 1, r >>= 1){
      if((l & 1) == 1) ret += tree[l++];
      if((r & 1) == 1) ret += tree[--r];
    }
    return ret; 
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    // input
    n = Integer.parseInt(br.readLine());
    x = Integer.parseInt(br.readLine());

    // init
    cnt = new long[MX * 2];
    dist = new long[MX * 2];
    
    update(x, 1L, cnt);
    update(x, (long)x, dist);

    // Query
    long ans = 1;
    while(n-- > 1){
      x = Integer.parseInt(br.readLine());

      long left = Math.abs(sumQuery(0, x, dist) - sumQuery(0, x, cnt) * x) % MOD;
      long right = Math.abs(sumQuery(x+1, MX, dist) - sumQuery(x+1, MX, cnt) * x) % MOD;

      ans = (ans * (left + right) % MOD) % MOD;

      update(x, 1L, cnt);
      update(x, (long)x, dist);
    }

    System.out.println(ans);
  }
}