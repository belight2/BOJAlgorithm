import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	public static void fill_array(int[][] arr) {
		for(int i = 2; i < 30; i++)
			for(int j = i; j <30; j++)
				arr[i][j] = arr[i][j-1] + arr[i-1][j-1];
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int x, y;
		int[][] arr = new int[30][30];
		for(int i = 1; i <30; i++)
			arr[1][i] = i;
		fill_array(arr);
		int t = Integer.parseInt(br.readLine());
		for(int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			bw.write(String.valueOf(arr[x][y])+"\n");
		}
		bw.flush();
		bw.close();
	}

}