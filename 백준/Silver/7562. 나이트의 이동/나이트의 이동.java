import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static Queue<int[]> q = new LinkedList<>();
	static int dist[][];
	static int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
	static int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
	static void BFS(int x, int y) {
		q.add(new int[] {x,y});
		dist[x][y] = 1;
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			for(int dir = 0; dir < 8; dir++) {
				int nx = cur[0] + dx[dir];
				int ny = cur[1] + dy[dir];
				if( nx < 0 || nx >= n || ny < 0 || ny >= n ) continue;
				// 모를만한 것
				if( dist[nx][ny] > 0 && dist[nx][ny] <= dist[cur[0]][cur[1]] + 1 ) continue;
				q.add(new int[] {nx,ny});
				dist[nx][ny] = dist[cur[0]][cur[1]] + 1;
			}
		}
	}
 	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int t = Integer.parseInt(br.readLine());
		while( t-- > 0) {
			n = Integer.parseInt(br.readLine());
			dist = new int[n][n];
			st = new StringTokenizer(br.readLine());
			BFS(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			st = new StringTokenizer(br.readLine());
			sb.append((dist[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())]- 1)+"\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
	}

}
