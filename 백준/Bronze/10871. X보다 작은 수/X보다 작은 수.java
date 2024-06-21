import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(input.readLine());
    StringBuilder sb = new StringBuilder();
    int N = Integer.parseInt(st.nextToken());
    int X = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(input.readLine());
    while(N --> 0){
      int A = Integer.parseInt(st.nextToken());
      if(A >= X) continue;
      sb.append(A+" ");
    }
    output.write(sb.toString());
    output.flush();
    output.close();
    input.close();
  }
}