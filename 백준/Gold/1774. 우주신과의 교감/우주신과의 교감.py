#Authored by : chjh2129
import sys, heapq
'''
  8 2
  1 2
  5 5
  2 1 
  9 9
  24 21
  6 -1
  0 0
  8 8
  1 2
  3 4

  다음과 같은 예제에서 처리를 잘해야합니다.

  미리 연결되어 있는 정점들은 가중치가 0인 간선을 추가로 인접리스트에 추가한 다음

  프림 알고리즘을 사용하면 풀이할 수 있습니다.
'''
input = sys.stdin.readline

def main() -> None:
  # input & init
  N, M = map(int, input().split())
  
  G: list[list[tuple]] = [ [] for _ in range(N+1) ]  
  chk: list[bool] = [ False for _ in range(N+1) ]
  
  Pos: list[tuple] = [(0, 0)] + [ (x, y) for x, y in (map(int, input().split()) for _ in range(N)) ]

  for u, v in (map(int, input().split()) for _ in range(M)):
    G[u].append((0, v))
    G[v].append((0, u))

  # solve
  for i in range(1, N):
    for j in range(i+1, N+1):
      dx: int = Pos[i][0] - Pos[j][0]
      dy: int = Pos[i][1] - Pos[j][1]
      dist: int = dx*dx + dy*dy
      G[i].append((dist, j))
      G[j].append((dist, i))
  
  pq: heapq[tuple] = []
  chk[1] = True
  for cost, nxt in G[1]: heapq.heappush(pq, (cost, 1, nxt))

  cnt: int = 0
  ans: float = 0.0

  while cnt < N - 1:
    dist, prv, cur = heapq.heappop(pq)
    if not chk[cur]:
      chk[cur] = True
      cnt += 1
      ans += dist ** 0.5

      for nxdist, nxt in G[cur]:
        if not chk[nxt]:
          heapq.heappush(pq, (nxdist, cur, nxt))
  
  # output
  print("%.2f" % ans)
  
sys.exit(main())