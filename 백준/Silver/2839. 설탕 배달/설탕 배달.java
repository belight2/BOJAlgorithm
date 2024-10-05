import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = Integer.parseInt(br.readLine());
		int bag = 0;
		
		if( N % 5 == 0)
		{
			bag = bag + N/5;
		}
		else
		{
			int y = 0;
			int S;
			while(true)
			{
				y++;
				S =  N - 3 * y;
				if( S % 5 == 0)
				{
					bag += y + S / 5;
					break;
				}
				else if( N == 3 * y)
				{
					bag += y;
					break;
				}
				else if( 3 * ( y + 1 ) > N )
				{
					bag = -1;
					break;
				}
				
			}
		}
		bw.write(String.valueOf(bag));
		bw.flush();
		bw.close();
		
	}

}