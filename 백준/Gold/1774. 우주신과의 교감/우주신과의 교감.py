#Authored by : chjh2129
import sys

input = sys.stdin.readline

def find(x: int, p: list[int]) -> int:
  root: int = x
  while p[root] > 0: root = p[root]
  while p[x] > 0:
    nxt, p[x] = p[x], root
    x = nxt
  return root 

def union(x: int, y: int, p: list[int]) -> bool:
  x = find(x, p)
  y = find(y, p)
  if x == y: return False
  if p[x] == p[y]: p[x] -= 1
  if p[x] > p[y]: x, y = y, x
  p[y] = x
  return True

def main() -> None:
  # input & init
  N, M = map(int, input().split())
  
  Pos: list[tuple] = [(0, 0)] + [ (x, y) for x, y in (map(int, input().split()) for _ in range(N)) ]
  P: list[int] = [ -1 for _ in range(N+1) ]
  cnt: int = 0
  Links: list[tuple] = []

  for u, v in (map(int, input().split()) for _ in range(M)):
    if union(u, v, P):
      cnt += 1

  # solve
  for i in range(1, N):
    for j in range(i+1, N+1):
      dx: int = Pos[i][0] - Pos[j][0]
      dy: int = Pos[i][1] - Pos[j][1]
      dist: int = dx*dx + dy*dy
      Links.append((dist, i, j))
  
  Links.sort(key=lambda x: x[0])

  ans: float = 0.0
  for dist, u, v in Links:
    if cnt == N - 1: break
    if union(u, v, P):
      cnt += 1
      ans += dist ** 0.5
  
  # output
  print("%.2f" % ans)
  

sys.exit(main())