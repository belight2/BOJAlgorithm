#Authored by : chjh2129
import sys
'''
  발전소가 설치된 도시들은 서로 떨어져있지만 케이블로 연결될 필요도 없습니다.

  따라서 가상의 정점 N+1번을 두고 발전소가 설치된 도시는 미리 연결을 해놓습니다.

  정점의 개수는 N+1이 되고 간선은 총 N개가 필요합니다.
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
  N, M, K = map(int, input().split())

  cnt: int = 0
  P: list[int] = [ -1 for _ in range(N+2) ]
  for cur in list(map(int, input().split())): 
    union(N+1, cur, P)
    cnt += 1
  
  Edge: list[tuple] = [ (cost, u, v) for u, v, cost in (map(int, input().split()) for _ in range(M)) ]

  # solve
  Edge.sort(key = lambda x: x[0])

  ans:int = 0
  for cost, u, v in Edge:
    if cnt == N: break
    if union(u, v, P):
      cnt += 1
      ans += cost
  
  # output
  print(ans)


sys.exit(main())