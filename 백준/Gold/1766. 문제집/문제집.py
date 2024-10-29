#Authored by : chjh2129
import sys
from heapq import heappush as hpush, heappop as hpop

'''
  우선순위 큐로 위상 정렬을 수행합니다.

  낮은 번호의 문제 즉, 쉬운 문제를 먼저 풀도록 합니다.
'''

input = sys.stdin.readline

def main() -> None:
  # input & init
  n, m = map(int, input().split())
  
  adj = [ [] for _ in range(n+1) ]
  deg = [ 0 for _ in range(n+1) ]

  for u, v in (map(int, input().split()) for _ in range(m)):
    adj[u].append(v)
    deg[v] += 1
  
  # topological sort
  pq: list[int] = []
  ans: list[int] = []

  for i in range(1, n+1):
    if not deg[i]:
      hpush(pq, i)

  while pq:
    cur = hpop(pq)
    ans.append(cur)

    for nxt in adj[cur]:
      deg[nxt] -= 1
      if not deg[nxt]:
        hpush(pq, nxt)
  
  # output
  print(*ans)

sys.exit(main())