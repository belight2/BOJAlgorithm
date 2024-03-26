import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Deque<Integer> dq = new ArrayDeque<>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int res = 0;
		st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= n; i++) {
			dq.add(i);
		}
		while(m--> 0) {
			int x = Integer.parseInt(st.nextToken());
			int cnt = 0;
			while(dq.peek() != x) {
				dq.add(dq.peek());
				dq.poll();
				cnt++;
			}
			res += Math.min(cnt, dq.size()-cnt);
			dq.poll();
		}
		bw.write(String.valueOf(res));
		bw.flush();
		bw.close();
	}

}
