#Authored by : chjh2129
import sys
from collections import deque

input = sys.stdin.readline

def main() -> None:
  N, M = map(int, input().split())
  P = [0] + [ *map(int, input().split()) ] # Parent Info

  # variables
  G = [ [] for _ in range(N+1) ] # Graph
  W = [ 0 for _ in range(N+1) ] 
  
  for u in range(2, N+1):
    G[u].append(P[u])
    G[P[u]].append(u)
  
  for _ in range(M):
    u, v = map(int, input().split())
    W[u] += v
  
  Q: deque = deque()
  Q.append(1);
  while Q:
    cur = Q.popleft()
    for nxt in G[cur]:
      if nxt != P[cur]:
        W[nxt] += W[cur]
        Q.append(nxt)
  
  _, *ans = W
  print(*ans)

sys.exit(main())