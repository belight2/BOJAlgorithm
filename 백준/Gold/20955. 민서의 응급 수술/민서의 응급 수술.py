#Authored by : chjh2129
import sys

# 재귀 깊이 재설정
sys.setrecursionlimit(100100)

input = sys.stdin.readline

def DFS(cur:int, G:list[list[int]], vis:list[bool]) -> None:
  vis[cur] = True
  for nxt in G[cur]:
    if not vis[nxt]:
      DFS(nxt, G, vis)

def main() -> None:
  # 정점 개수 N, 간선 개수 M
  N, M = map(int, input().split())

  # variables
  G: list[list[int]] = [ [] for _ in range(N+1) ] # Graph
  vis: list[bool] = [ False for _ in range(N+1) ] # visited array

  # input
  for _ in range(M):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)
  
  # solve
  group:int = 0
  for vertex in range(1, N+1):
    if not vis[vertex]:
      group += 1
      DFS(vertex, G, vis)

  # output
  print((group - 1) + (M + group - 1) - (N - 1))

sys.exit(main())