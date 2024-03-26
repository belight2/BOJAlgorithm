import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
	private static void fillArray(Integer[] arr, StringTokenizer st) {
		for(int i = 0; i < arr.length; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int sum = 0;
		int size = Integer.parseInt(br.readLine());
		Integer[] A_arr = new Integer[size];
		Integer[] B_arr = new Integer[size];
		
		fillArray(A_arr, new StringTokenizer(br.readLine(), " "));
		fillArray(B_arr, new StringTokenizer(br.readLine(), " "));
		
		Arrays.sort(A_arr);
		Arrays.sort(B_arr, Collections.reverseOrder());
		
		for(int i = 0; i < size; i++ ) {
			sum = sum + (A_arr[i] * B_arr[i] );
		}
		
		bw.write(String.valueOf(sum));
		
		bw.flush();
		bw.close();
	}

}
