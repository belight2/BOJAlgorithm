#Authored by : chjh2129
import sys

input = sys.stdin.readline

def main() -> None:
  # input & init
  n = int(input())

  nxt = [ [ 0 for _ in range(n+1) ] for _ in range(31) ]
  nxt[0] = [0] + list(map(int, input().split()))

  for k in range(1, 31):
    for i in range(1, n+1):
      nxt[k][i] = nxt[k-1][nxt[k-1][i]]

  # solve
  q = int(input())
  for f, x in (map(int, input().split()) for _ in range(q)):
    for i in range(30, -1, -1):
      if f & (1 << i):
        x = nxt[i][x]

    print(x)
  
sys.exit(main())