import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { 1, 0, -1, 0 };
	static int n, m, g, r;
	static int map[][];
	static int vis[][][];
	static boolean isused[];
	static int pos[];
	static int ans;
	static ArrayList<Integer> ableGround = new ArrayList<Integer>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		g = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		pos = new int[r+g];
		vis = new int[n][m][2];
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 2) ableGround.add(i*100+j);
			}
		}
		isused = new boolean[ableGround.size()];
		decideGreens(0, 0);
		sb.append(ans);
		System.out.println(sb.toString());
	}
	public static void decideGreens(int k, int idx) {
		if(k == g) {
			decideReds(0, 0);
			return;
		}
		for(int i = idx; i < ableGround.size(); i++) {
			if(isused[i]) continue;
			isused[i] = true;
			pos[k] = ableGround.get(i);
			decideGreens(k+1, i);
			isused[i] = false;
		}
	}
	public static void decideReds(int k, int idx) {
		if(k == r) {
			ans = Math.max(ans, solve());
			return;
		}
		for(int i = idx; i < ableGround.size(); i++) {
			if(isused[i]) continue;
			isused[i] = true;
			pos[g+k] = ableGround.get(i);
			decideReds(k+1, i);
			isused[i] = false;
		}
	}
	
	public static int solve() {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				vis[i][j][0] = -1;
				vis[i][j][1] = -1;
			}
		}
		bfs();
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(vis[i][j][0] == 2) cnt++;
			}
		}
		return cnt;
	}
	public static void bfs() {
		Queue<int[]> q = new LinkedList<int[]>();
		for(int i = 0; i < g; i++) {
			q.add(new int[] {pos[i]/100, pos[i]%100, 0, 0});
			vis[pos[i]/100][pos[i]%100][0] = 0;
			vis[pos[i]/100][pos[i]%100][1] = 0;
		}
		for(int i = g; i < r+g; i++){
			q.add(new int[] {pos[i]/100, pos[i]%100, 1, 0});
			vis[pos[i]/100][pos[i]%100][0] = 1;
			vis[pos[i]/100][pos[i]%100][1] = 0;
		}
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			int cx = cur[0], cy = cur[1], state = cur[2], cnt = cur[3];
			if(vis[cx][cy][0] == 2) continue;
			for(int dir = 0; dir < 4; dir++) {
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(map[nx][ny] == 0 || vis[nx][ny][0] == 2) continue;
				if(vis[nx][ny][0] == -1) {
					vis[nx][ny][0] = state;
					vis[nx][ny][1] = cnt + 1;
					q.add(new int[] {nx, ny, state, cnt+1});
					continue;
				}
				if(vis[nx][ny][0] == (state+1)%2 && vis[nx][ny][1] == cnt+1) {
					vis[nx][ny][0] = 2;
				}
			}
		}
	}

}