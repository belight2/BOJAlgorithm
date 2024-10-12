#Authored by : chjh2129
import io, os, sys

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def solve() -> int:
  N, M = map(int, input().decode().split())
  for i in range(M):
    u, v = map(int, input().decode().split())
  return N-1

def main() -> None:
  T = int(input())
  for i in range(T):
    print(solve())

sys.exit(main())