#Authored by : chjh2129
import sys
from collections import deque

input = sys.stdin.readline

def main() -> None:
  # input & init
  n, m, x, y = map(int, input().split())
  
  cost = [ ( x, i ) for x, i in zip(map(int, input().split()), range(1, n+1)) ]

  q = deque()
  adj = [ [] for _ in range(n+1) ] 
  security = [ 0 for _ in range(n+1) ]

  for u, v in (map(int, input().split()) for _ in range(m)):
    adj[u].append(v)
    adj[v].append(u)
  
  for u in map(int, input().split()):
    security[u] = 1
    q.append(u)

  # solve
  while q:
    cur = q.popleft()
    for nxt in adj[cur]:
      if security[nxt] and security[nxt] <= security[cur] + 1:
        continue;
      security[nxt] = security[cur] + 1
      q.append(nxt)

  totCost = list()
  for c, v in cost:
    if not security[v] and c:
      print(-1)
      return
    totCost.append(c * (security[v] - 1))
  
  totCost.sort(reverse=True)
  # output
  print(sum(totCost[:x]))

sys.exit(main())