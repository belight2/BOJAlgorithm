import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int size, idx;
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		size = Integer.parseInt(st.nextToken());
		idx = Integer.parseInt(st.nextToken());
		int[] arr = new int[size];
		
		st = new StringTokenizer(br.readLine(), " ");
		for(int i = 0; i < size; i ++ ) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr);
		bw.write(String.valueOf(arr[idx-1])+"\n");
		bw.flush();
		bw.close();
	}
}