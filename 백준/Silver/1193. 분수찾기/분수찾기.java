import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int X = Integer.parseInt(br.readLine());
		int deno, nume;
		int n = 1;
		
		while(true)
		{
			if( ( n * ( n - 1 ) )/ 2 < X && X <= (n * ( n + 1 ) / 2) ) {
				break;
			}
			n++;
		}
		
		X = X - ( n * ( n - 1 ) / 2 );
		
		if( n % 2 != 0 )
		{	
			nume = n - ( X - 1 );
			deno = 1 +( X - 1 );
		}
		else
		{
			nume = 1 +( X - 1 );
			deno = n - ( X - 1 );;
		}
		
		
		bw.write(nume + "/" + deno);
		bw.flush();
		bw.close();
		
		
	}

}