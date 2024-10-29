#Authored by : chjh2129
import sys
from collections import deque

input = sys.stdin.readline

def solve() -> int:
  # input & init
  n, k = map(int, input().split())
  t = [0] + list(map(int, input().split()))
  
  adj = [ [] for _ in range(n+1) ]
  deg = [ 0 for _ in range(n+1) ]
  d = [ 0 for _ in range(n+1) ]

  for u, v in (map(int, input().split()) for _ in range(k)):
    adj[u].append(v)
    deg[v] += 1

  # topological sort
  q: deque = deque()

  for i in range(1, n+1):
    if not deg[i]:
      q.append(i)
      d[i] = t[i]
  
  while q:
    cur = q.popleft()

    for nxt in adj[cur]:
      d[nxt] = max(d[nxt], t[nxt] + d[cur])

      deg[nxt] -= 1
      if not deg[nxt]:
        q.append(nxt)
  
  # output
  return d[int(input())]

def main() -> None:
  t = int(input())
  for _ in range(t):
    print(solve())

sys.exit(main())