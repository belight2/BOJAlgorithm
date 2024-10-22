#Authored by : chjh2129
import sys
'''
  가상의 정점(n+1)이 하나 더 있다고 가정하게 된다면

  i번 우물을 팔 때 드는 비용을 i번과 (n+1)번을 잇는 간선의 가중치라고 생각할 수 있습니다.

  문제에서 주어진 그래프를 문제를 풀기 위해 변형하는 것을 그래프 모델링이라고 합니다.
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
  N: int = int(input())
  P: list[int] = [ -1 for _ in range(N+2) ]  

  # 각 우물을 가상의 정점 N+1가 이어준다.
  Edge: list[tuple] = [ (cost, cur, N+1) for cur, cost in zip(range(1, N+1), (int(input()) for _ in range(N))) ]

  for i in range(1, N):
    cost: list[int] = [0] + list(map(int, input().split()))
    for j in range(i+1, N+1):
      Edge.append((cost[j], i, j))
  
  # solve
  Edge.sort(key=lambda x: x[0])
  cnt, ans = 0, 0
  for cost, u, v in Edge:
    if cnt == N: break
    if union(u, v, P):
      cnt += 1
      ans += cost

  # output
  print(ans)

sys.exit(main())