#Authored by : chjh2129
import sys
# heappush와 heappop 명령어가 너무 김, hpush, hpop으로 축약해서 import
from heapq import heappush as hpush, heappop as hpop

# input을 빠른 입력으로 대체
input = sys.stdin.readline

def main() -> None:
  n, m, x = map(int, input().split())

  # 거리 테이블
  d = [ [ 0x3f3f3f3f for _ in range(n+1) ] for _ in range(n+1) ]
  
  # 인접 리스트
  adj = [ [] for _ in range(n+1) ]

  # 간선 정보
  for u, v, w in (map(int, input().split()) for _ in range(m) ):
    adj[u].append((w, v))
  
  for st in range(1, n+1):
    pq = [] # heap
    
    # init
    d[st][st] = 0
    hpush(pq, (d[st][st], st))
    
    # dijkstra
    while pq:
      cw, cx = hpop(pq)

      if d[st][cx] != cw:
        continue

      for nw, nx in adj[cx]:
        if d[st][nx] > d[st][cx] + nw:
          d[st][nx] = d[st][cx] + nw
          hpush(pq, (d[st][nx], nx))
  # for loop done

  # 최댓값 찾기
  ans = 0
  for i in range(1, n+1):
    ans = max(ans, d[i][x] + d[x][i])
    
  # output
  print(ans)


sys.exit(main())