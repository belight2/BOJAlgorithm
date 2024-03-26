import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	private static int[] fibonacci(int n, int[] prev, int[] curr){
		int[] next = new int[2];
		if(n == 0) {
			return prev;
		}
		else if(n == 1) {
			return curr;
		}
		for(int i = 2; i < n+1; i++) {
			next[0] = prev[0] + curr[0];
			next[1] = prev[1] + curr[1];
			prev = curr.clone();
			curr = next.clone();
		}
		return curr;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int[] prev = new int[]{ 1, 0 };
		int[] curr = new int[]{ 0, 1 };
		int t = Integer.parseInt(br.readLine());
		for(int i = 0; i < t; i++) {
			prev[0] = 1; prev[1] = 0; curr[0] = 0; curr[1] = 1;
			int[] r = fibonacci(Integer.parseInt(br.readLine()), prev, curr);
			bw.write(String.valueOf(r[0])+" "+String.valueOf(r[1])+"\n");
		}
		bw.flush();
		bw.close();
	}

}