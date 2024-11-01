#Authored by : chjh2129
import sys
from heapq import heappush as hpush, heappop as hpop
'''
  각 도시에서 면접장으로 가는 거리를 구하면 TLE,

  반대로 면접장에서 각 도시로 가는 거리를 구하는 방법을 채택

  간선 정보의 방향을 거꾸로 저장한 다음, 면접장이 배치된 도시를 우선순위 큐에 모두 넣고 다익스트라 진행
'''
input = sys.stdin.readline

def main() -> None:
  # input & init
  n, m, k = map(int, input().split())

  # 인접 리스트
  adj = [ [] for _ in range(n+1) ]

  # 거리 배열
  d = [ int(1e10 + 10) for _ in range(n+1) ]

  # 간선 정보
  for u, v, w in (map(int, input().split()) for _ in range(m)):
    adj[v].append((w, u))
  
  # 최소 힙
  pq = [ ]
  for x in map(int, input().split()):
    d[x] = 0
    hpush(pq, (d[x], x))
  
  # solve
  while pq:
    cw, cx = hpop(pq)
    
    if d[cx] != cw: continue

    for nw, nx in adj[cx]:
      if d[nx] > d[cx] + nw:
        d[nx] = d[cx] + nw
        hpush(pq, (d[nx], nx))
  
  # output
  aidx = d.index(max(d[1:]))
  print(aidx)
  print(d[aidx])

sys.exit(main())