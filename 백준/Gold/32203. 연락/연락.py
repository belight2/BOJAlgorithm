#Authored by : chjh2129
import sys

input = sys.stdin.readline

def find(x: int, P: list[int]) -> int:
  if P[x] < 0 : return x
  P[x] = find(P[x], P)
  return P[x]

def union(x: int, y: int, P: list[int], C: list[list[int]], ans: int) -> int:
  x = find(x, P)
  y = find(y, P)
  if x == y: return ans
  if P[x] == P[y]: P[x]-=1
  if P[x] > P[y]: x, y = y, x

  ans -= C[x][0] * C[x][1] + C[y][0] * C[y][1]
  C[x][0] += C[y][0]
  C[x][1] += C[y][1]
  ans += C[x][0] * C[x][1]

  P[y] = x
  return ans

def main() -> None:
  # 사람 수, 모임 수
  N, M = map(int, input().split())
  
  # Parent info
  P: list[int] = [ -1 for _ in range(N+1) ]
  # 서로 연락할 수 있는 남녀 쌍
  C: list[list[int]] = [ [ 0, 0 ] for _ in range(N+1) ]
  
  # 성별 정보
  G: list[int] = list(map(int, input().split()))

  # 성별 정보에 따라 mapping
  for i in range(len(G)):
    if G[i] % 2 == 0: C[i+1][0] = 1
    else: C[i+1][1] = 1

    
  # solve & output
  ans: int = 0
  for _ in range(M):
    u, v = map(int, input().split())
    ans = union(u, v, P, C, ans)
    print(ans)


sys.exit(main())