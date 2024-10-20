#Authored by : chjh2129
import sys
from collections import deque

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