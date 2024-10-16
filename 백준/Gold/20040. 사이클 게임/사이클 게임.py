#Authored by : chjh2129
import sys

input = sys.stdin.readline

def find(x: int, P: list[int]) -> int:
  if P[x] < 0: return x
  P[x] = find(P[x], P)
  return P[x]

def union(x: int, y: int, P: list[int]) -> bool:
  x = find(x, P)
  y = find(y, P)
  if x == y: return False
  
  if P[x] == P[y]: P[x] -= 1
  if P[x] > P[y]: x, y = y, x
  P[y] = x
  return True

def main() -> None:
  # input
  N, M = map(int, input().split())
  
  # Parent info
  P:list[int] = [ -1 for _ in range(N) ]

  # solve
  ans:int = 0
  for round in range(1, M+1):
    u, v = map(int, input().split())
    if not union(u, v, P):
      ans = round
      break
  
  # output
  print(ans)

sys.exit(main())