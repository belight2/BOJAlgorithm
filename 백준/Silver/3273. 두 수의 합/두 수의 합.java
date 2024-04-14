import java.io.*;
import java.util.StringTokenizer;

/*
두 수의 합
 */
public class Main {
  static boolean[] f = new boolean[20000001];
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();
    int n = Integer.parseInt(br.readLine());
    StringTokenizer st = new StringTokenizer(br.readLine());
    int[] a = new int[n];
    for(int i = 0; i < n; i++) a[i] = Integer.parseInt(st.nextToken());
    int x = Integer.parseInt(br.readLine());
    int ans = 0;
    for(int i = 0; i < n; i++){
      f[a[i]] = true;
      if(x - a[i] < 0 || x - a[i] > 2000000) continue;
      if(f[x-a[i]] && x-a[i] != a[i]) ans++;
    }
    sb.append(ans);
    bw.write(sb.toString());
    bw.flush();
    bw.close();
  }
}