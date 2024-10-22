#Authored by : chjh2129
import sys

input = sys.stdin.readline

def find(x: int, p: list[int]) -> int:
  root: int = x
  while p[root] > 0:
    root = p[root]
  
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
  Edge: list[tuple] = [ (u, v, cost) for u, v, cost in (map(int, input().split()) for _ in range(M)) ]
  P: list[int] = [ -1 for _ in range(N+1) ]

  # solve
  Edge.sort(key = lambda x: x[2])

  '''
    마을을 총 2개로 나누어야 하므로 cnt가 2가 되면 종료
  '''
  cnt, ans = N, 0
  for u, v, cost in Edge:
    if cnt == 2: break
    if union(u, v, P):
      cnt -= 1
      ans += cost

  # output
  print(ans)

sys.exit(main())