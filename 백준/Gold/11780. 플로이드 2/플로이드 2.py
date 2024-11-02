#Authored by : chjh2129
import sys

input = sys.stdin.readline

def main() -> None:
  # input & init
  n = int(input())
  m = int(input())

  INF = 0x3f3f3f3f # infinity value

  # 인접 행렬(거리 테이블)
  d = [ [ INF for _ in range(n+1)] for _ in range(n+1) ]

  # nxt[a][b] = c, 정점 a에서 정점 b의 최단경로가 a -> c -> ... -> b임을 의미
  nxt = [ [ 0 for _ in range(n+1) ] for _ in range(n+1) ]

  for u, v, w in (map(int, input().split()) for _ in range(m)):
    d[u][v] = min(d[u][v], w) # u -> v 간선이 여러 개 있을 수 있으므로 그 중 가중치가 최소인 것만 저장
    nxt[u][v] = v # 경로 추적 배열 초기화
  
  # solve
  for i in range(1, n+1): d[i][i] = 0 # 자기자신으로 이동은 0임

  # 플로이드-와샬
  for k in range(1, n+1):
    for i in range(1, n+1):
      for j in range(1, n+1):
        if d[i][k] + d[k][j] < d[i][j]:
          d[i][j] = d[i][k] + d[k][j]

          nxt[i][j] = nxt[i][k] # 경로 추적 배열 갱신

  # output
  # 거리 테이블 출력
  for row in d[1:]:
    for val in row[1:]:
      print(val if val != INF else 0, end = ' ')
    print()

  # d[i][j]가 0이 아니라면 경로를 출력, 0이면 0 출력  
  for i in range(1, n+1):
    for j in range(1, n+1):
      if not d[i][j] or d[i][j] == INF:
        print(0)
        continue
      # 경로 추적
      path = []
      
      st = i
      while st != j:
        path.append(st)
        st = nxt[st][j]
      path.append(j)

      print(len(path), *path)

sys.exit(main())