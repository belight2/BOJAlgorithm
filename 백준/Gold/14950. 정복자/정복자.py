#Authored by : chjh2129
import sys
'''
  무방향 가중치 연결 그래프입니다.

  정복할 때마다 t만큼 모든 도로의 비용이 증가하지만

  모든 도시를 정복해야 하므로 추가되는 비용은 정점의 개수에 비례하게 증가합니다.

  따라서 MST가 되는 간선들의 가중치의 합과 정점의 개수에 맞추어 추가 비용을 더해주시면 됩니다.
'''
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
  N, M, T = map(int, input().split())
  Edges: list[tuple] = [ (u, v, cost) for u, v, cost in (map(int, input().split()) for _ in range(M)) ]
  P: list[int] = [ -1 for _ in range(N+1) ]

  # solve
  Edges.sort(key = lambda x: x[2])
  ans, cnt = 0, 0
  for u, v, cost in Edges:
    if union(u, v, P):
      cnt += 1
      ans += cost
      if cnt == N - 1: break
  
  # cnt값 조정
  cnt = (N - 2) * (N - 1) // 2

  # output
  print(ans + cnt * T)
  
sys.exit(main())