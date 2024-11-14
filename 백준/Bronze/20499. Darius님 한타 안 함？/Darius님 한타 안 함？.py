#Authored by : chjh2129
import sys

input = sys.stdin.readline

def main() -> None:
  a, b, c = map(int, input().split('/'))

  if a + c < b or b == 0:
    print("hasu")
  else:
    print("gosu")
sys.exit(main())