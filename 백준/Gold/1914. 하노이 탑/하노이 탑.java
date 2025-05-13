import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    private static StringBuilder sb = new StringBuilder();
    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());        

        BigInteger cnt = new BigInteger("2");
        BigInteger offset = new BigInteger("-1");
        sb.append(cnt.pow(N).add(offset).toString()).append("\n");

        if(N <= 20) {
            hanoi_tower(1, 2, 3, N);
        }

        System.out.println(sb.toString());
    }

    private static void hanoi_tower(int A, int B, int C, int N) {
        if(N == 1) {
            sb.append(A).append(" ").append(C).append("\n");
            return;
        }
        hanoi_tower(A, C, B, N - 1);
        sb.append(A).append(" ").append(C).append("\n");
        hanoi_tower(B, A, C, N - 1);

    }
}