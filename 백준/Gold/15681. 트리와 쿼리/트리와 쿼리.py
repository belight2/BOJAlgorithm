#Authored by : chjh2129
import sys
sys.setrecursionlimit(100005)

input = sys.stdin.readline

def dfs(cur: int, G:list[list], vis:list[bool], ans:list[int]) -> int:
  vis[cur] = True
  for nxt in G[cur]:
    if vis[nxt]:
      continue
    ans[cur] += dfs(nxt, G, vis, ans)
  return ans[cur]

def main() -> None:
  N, R, Q = map(int, input().split())
  
  # variable
  ans: list[int] = [1] * (N+1)
  vis: list[bool] = [False] * (N+1)
  G: list[list] = [list() for _ in range(N+1)]

  for _ in range(N-1):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)

  # solve  
  dfs(R, G, vis, ans)

  # output
  for _ in range(Q):
    S = int(input())
    print(ans[S])

sys.exit(main())