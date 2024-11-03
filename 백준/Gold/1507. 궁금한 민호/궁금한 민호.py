#Authored by : chjh2129
import sys
'''
  u, v를 제외한 다른 정점을 k라고 합시다.

  u에서 k를 거쳐 v로 가는 거리를 d[u][k] + d[k][v]로 계산합니다. 이를 ukv라고 해봅시다.

  ukv는 d[u][v]보다 작은 경우, 문제의 조건에 맞지 않으므로 -1을 출력하고 종료한다. (이는 입력으로 주어진 행렬이 최단 거리를 기록하고 있지 않다고 판단할 수 있음.)

  ukv가 d[u][v]와 값이 같다면, d[u][v]는 k를 경유지로 하여 이동한 도로이므로 u -> v를 직접 연결한 도로가 없다고 판단할 수 있음.
'''
input = sys.stdin.readline

def main() -> None:
  # input & init
  n = int(input())
  
  # 인접 행렬 0-indexed
  d = [ list(map(int, input().split())) for _ in range(n) ]

  # u[x][y] = True, (x -> y)로 이동하는 직통 도로가 있음.
  u = [ [ False for _ in range(n) ] for _ in range(n) ]

  # solve
  for i in range(n):
    for j in range(n):
      isunit = True
      for k in range(n):
        if k == i or k == j: continue
        
        cur = d[i][k] + d[k][j]
        if cur < d[i][j]:
          print(-1)
          return
        if cur == d[i][j]: isunit = False
      if isunit:
        u[i][j] = u[j][i] = True
  
  ans = 0
  for i in range(n):
    for j in range(i+1, n):
      if u[i][j]:
        ans += d[i][j]

  # output
  print(ans)

sys.exit(main())