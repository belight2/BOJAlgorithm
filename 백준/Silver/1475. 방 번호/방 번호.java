import java.io.*;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();
    String N = br.readLine();
    int[] freq = new int[9];
    for(char c : N.toCharArray()){
      int cur = c - '0';
      freq[(cur==9) ? 6 : cur]++;
    }
    freq[6] = (freq[6] + 1) / 2;
    sb.append(Arrays.stream(freq).max().getAsInt());
    bw.write(sb.toString());
    bw.flush();
    bw.close();
  }
}