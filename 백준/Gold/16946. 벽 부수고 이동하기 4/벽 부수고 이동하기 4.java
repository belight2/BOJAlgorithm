import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

/*
  flood fill 기법을 사용합니다.

  너비우선탐색을 진행하면서 방문하는 점들을 모두 merge해줍니다.

  union by size로 진행해 각 그룹마다 크기를 구해줍니다.

  이중 for loop를 돌면서 벽이라면 인접한 4칸을 확인해 서로 다른 그룹인 경우 더한 값을 출력하면 됩니다.   

  n * m 2차원 배열의 (x, y) 위치에 대해서 x * m + y로 계산하게되면 각 칸마다 유일한 값을 가집니다.

  이를 노드의 번호를 가지고 union-find 하시면 됩니다.

  이렇게 2차원 배열에서 특정 영역들을 분리하거나 크기가 필요할 때 union-find를 사용할 수 있다.
 */
public class Main {
  public static final int[] dx = { 1, 0, -1, 0 };
  public static final int[] dy = { 0, 1, 0, -1 };
  
  public static Queue<int[]> q = new LinkedList<>();

  public static int n, m;
  public static char[][] board;
  public static boolean[][] vis;
  public static int[] p;

  public static int swap(int x, int y){ return x; }

  public static int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  public static void union(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(p[x] > p[y]) x = swap(y, y = x);
    p[x] += p[y];
    p[y] = x;
  }

  public static boolean OOB(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
  }

  public static void bfs(int sx, int sy){
    int root = sx * m + sy;
    
    q.add(new int[]{sx, sy});
    vis[sx][sy] = true;

    while(!q.isEmpty()){
      int[] cur = q.poll();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur[0] + dx[dir];
        int ny = cur[1] + dy[dir];
        if(OOB(nx, ny) || board[nx][ny] == '1'|| vis[nx][ny]) continue;
        
        q.add(new int[]{nx, ny});
        vis[nx][ny] = true;
        union(root, nx * m + ny);
      }
    }
  }

  public static int chk(int cx, int cy){
    List<Integer> group = new ArrayList<>();

    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(OOB(nx, ny) || board[nx][ny] == '1') continue;
      group.add(find(nx*m+ny));
    }
  
    // 중복 제거
    List<Integer> newGroup = group.stream().distinct().collect(Collectors.toList());

    int ret = 1;
    for(int cur : newGroup) ret += Math.abs(p[cur]);
    return ret % 10;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    // init
    board = new char[n][];
    vis = new boolean[n][m];
    p = new int[n*m+1];
    for(int i = 0; i < n*m+1; i++) p[i] = -1;

    // input2
    for(int i = 0; i < n; i++){
      String line = br.readLine();
      board[i] = line.toCharArray();
    }

    // solve
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(board[i][j] == '1' || vis[i][j]) continue;
        bfs(i, j);
      }
    }

    // mapping 
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        sb.append(board[i][j] == '0' ? 0 : chk(i, j)); 
      }
      sb.append('\n');
    }

    // output
    System.out.println(sb.toString());
  }
  
}