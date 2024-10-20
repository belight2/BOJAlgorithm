#Authored by : chjh2129
import sys
from collections import deque
'''
  flood fill 기법을 사용합니다.

  너비우선탐색을 진행하면서 방문하는 점들을 모두 merge해줍니다.

  union by size로 진행해 각 그룹마다 크기를 구해줍니다.

  이중 for loop를 돌면서 벽이라면 인접한 4칸을 확인해 서로 다른 그룹인 경우 더한 값을 출력하면 됩니다.   

  n * m 2차원 배열의 (x, y) 위치에 대해서 x * m + y로 계산하게되면 각 칸마다 유일한 값을 가집니다.

  이를 노드의 번호를 가지고 union-find 하시면 됩니다.

  이렇게 2차원 배열에서 특정 영역들을 분리하거나 크기가 필요할 때 union-find를 사용할 수 있다.
'''
input = sys.stdin.readline

def find(x: int, p: list[int]) -> int:
  if p[x] < 0: return x
  p[x] = find(p[x], p)
  return p[x]

def union(x: int, y: int, p: list[int]) -> None:
  x = find(x, p)
  y = find(y, p)
  
  if x == y: return
  if p[x] > p[y]: x, y = y, x
  
  p[x] += p[y]
  p[y] = x

dx: list[int] = [1, 0, -1, 0]
dy: list[int] = [0, 1, 0, -1]

def bfs(sx: int, sy: int, board: list[str], vis: list[list[bool]], n: int, m: int, p: list[int]) -> None:
  global dx, dy
  
  root: int = sx * m + sy
  q: deque = deque()
  q.append((sx, sy))
  vis[sx][sy] = True
  
  while q:
    cx, cy = q.popleft()
    for dir in range(4):
      nx = cx + dx[dir]
      ny = cy + dy[dir]
      if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == '0' and not vis[nx][ny]:
        q.append((nx, ny))
        vis[nx][ny] = True
        union(root, nx * m + ny, p)


def main() -> None:
  # input
  n, m = map(int, input().split())
  board: list[str] = [ line for line in (input().rstrip() for _ in range(n)) ]

  # init
  vis: list[list[bool]] = [ [ False for _ in range(m) ] for _ in range(n) ]
  p: list[int] = [ -1 for _ in range(n*m+1) ]

  for i in range(n):
    for j in range(m):
      if board[i][j] == '0' and not vis[i][j]:
        bfs(i, j, board, vis, n, m, p)
  
  global dx, dy
  for x in range(n):
    for y in range(m):
      if board[x][y] == '0':
        print(0, end='')
        continue
      
      group: list[int] = []
      for dir in range(4):
        nx = x + dx[dir]
        ny = y + dy[dir]
        if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == '0':
          group.append(find(nx * m + ny, p))
      group = list(set(group))
      print((sum([abs(p[k]) for k in group]) + 1) % 10, end='')
      
    print()

sys.exit(main())