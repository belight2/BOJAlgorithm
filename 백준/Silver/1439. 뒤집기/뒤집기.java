import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	private static int StringCheck(String s, char state)
	{
		int c = 0;
		char x;
		char prev='i';
		for(int i = 0; i < s.length(); i++)
		{
			x = s.charAt(i);
			if(state != x && prev != x)
				c++;
			prev = x;
		}
		return c;
		
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String s = br.readLine();
		int zero_to_one, one_to_zero;
		zero_to_one = StringCheck(s, '0');
		one_to_zero = StringCheck(s, '1');
		bw.write(String.valueOf(Math.min(zero_to_one, one_to_zero)));
		bw.flush();
		bw.close();
	}

}