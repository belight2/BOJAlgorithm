import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int idx = 0;
		int start_idx = 0;
		int last_idx = 0;
		boolean inline = false;
		char x;
		
		String str = br.readLine();
		// '<', ' ', '>', 'a-z' or '0-9', 문자열 끝
		while(true)
		{
			if( idx >= str.length())
				break;
			x = str.charAt(idx);
			if ( x == '<')
			{
				bw.write(x);
				inline = true;
			}
			else if( x == ' ')
			{
				bw.write(x);
			}
			else if ( x == '>' )
			{
				bw.write(x);
				inline = false;
			}
			else {
				if(inline)
					bw.write(x);
				else {
					start_idx = idx;
					while(true) {
						if(idx + 1 >= str.length() || str.charAt(idx+1) == '<' || str.charAt(idx+1) == ' ') {
							last_idx = idx;
							break;
						}
						idx++;
					}
					for(int i = last_idx; i >= start_idx; i--)
						bw.write(str.charAt(i));
				}
			}
			idx++;
		}
		bw.flush();
		bw.close();

	}

}