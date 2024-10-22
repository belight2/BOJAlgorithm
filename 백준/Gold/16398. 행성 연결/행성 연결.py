#Authored by : chjh2129
import sys

input = sys.stdin.readline

def find(x: int, p: list[int]) -> int:
  root:int = x
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
  N: int = int(input())
  P: list[int] = [ -1 for _ in range(N+1) ]
  Edges: list[tuple] = []

  for i in range(1, N+1):
    cost: list[int] = list(map(int, input().split()))
    for j in range(i+1, N+1):
      Edges.append((cost[j-1], i, j))

  # solve
  Edges.sort(key=lambda x : x[0])

  cnt, ans = 0, 0
  for cost, u, v in Edges:
    if union(u, v, P):
      cnt += 1
      ans += cost
      if cnt == N - 1: break

  # output
  print(ans)
sys.exit(main())