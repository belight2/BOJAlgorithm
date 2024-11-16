#Authored by : chjh2129
import sys

input = sys.stdin.readline

def main() -> None:
  # input & init
  n, k = map(int, input().split())
  num = input().rstrip()

  # solve
  stk = list()
  for x in num:
    while k and stk and stk[-1] < x:
      k -= 1
      stk.pop()
    stk.append(x)
  
  while k:
    stk.pop()
    k -= 1
  
  # output
  print(''.join(stk))

sys.exit(main())