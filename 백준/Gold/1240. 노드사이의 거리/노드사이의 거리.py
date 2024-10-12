#Authored by : chjh2129
import sys

input = sys.stdin.readline

def dfs(prv:int, cur:int, G:list[list[tuple]], D:list[int]) -> None:
  for nxt, weight in G[cur]:
    if nxt != prv:
      D[nxt] = D[cur] + weight
      dfs(cur, nxt, G, D)

def main() -> None:
  N, M = map(int, input().split())

  # variable
  G = [ list() for _ in range(N+1) ]
  D = [ [0 for _ in range(N+1)] for _ in range(N+1) ] 
  
  for _ in range(N-1):
    u, v, w = map(int, input().split())
    G[u].append((v, w))
    G[v].append((u, w))
  
  # solve
  for i in range(1, N+1):
    dfs(-1, i, G, D[i])

  # output
  for _ in range(M):
    u, v = map(int, input().split())
    print(D[u][v])
  
sys.exit(main())