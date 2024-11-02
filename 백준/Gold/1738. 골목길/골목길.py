#Authored by : chjh2129
import sys
from collections import deque
'''
  양의 사이클이 존재하면서 그 양의 사이클에서 도착지로 이동이 가능한지 판별해야하는 문제 

  간선 방향을 역방향으로 따로 저장해 n을 출발지로 bfs로 전처리하여 해결할 수 있음.

  경로를 추적하는 방법은 테이블이 갱신될 때, prv로 따로 갱신해 처리

  물론, 1번에서 n으로 도달할 수 없는 경우도 -1를 출력해야 함.
'''
input = sys.stdin.readline

def main() -> None:
  # input & init
  n, m = map(int, input().split())

  # 간선 방향을 역으로 저장하는 인접리스트
  adj = [ [] for _ in range(n+1) ]

  # 방문 배열 
  vis = [ False for _ in range(n+1) ]

  # negative INF
  INF = int(-1e8)

  # 거리 테이블
  d = [ INF for _ in range(n+1) ]

  # 경로 추적 테이블
  prv = [ 0 for _ in range(n+1) ]

  # 간선 정보
  edges = []
  for u, v, w in (map(int, input().split()) for _ in range(m)):
    edges.append((u, v, w)) # 간선 추가
    adj[v].append(u) # 방향을 역으로하여 추가

  # solve
    
  # n을 출발지로 bfs 시작
  q = deque()
  vis[n] = True
  q.append(n)

  while q:
    cur = q.popleft()
    for nxt in adj[cur]:
      if not vis[nxt]:
        vis[nxt] = True
        q.append(nxt)
  # bfs done

  # Bellman-Ford 시작
  d[1] = 0
  for i in range(n):
    for u, v, w in edges:
      if u != INF and d[u] + w > d[v]:
        d[v] = d[u] + w
        prv[v] = u # 경로 추적을 위한 갱신

        if i == n-1 and vis[v]:
          print(-1)
          return
  # Bellman-Ford 끝

  # 1번 정점에서 n번 정점으로 이동이 불가하면 -1 출력
  if not vis[1]:
    print(-1)
    return

  # 경로 추적
  path = [ ]
  while n != 1:
    path.append(n)
    n = prv[n]
  path.append(1)

  # output
  print(*path[::-1])
  

sys.exit(main())