#Authored by : chjh2129
import sys

input = sys.stdin.readline

def main() -> None:
  n = int(input())
  k = int(input())
  ans = (n - k) >> 1;
  print(n-ans)
  print(ans)
sys.exit(main())