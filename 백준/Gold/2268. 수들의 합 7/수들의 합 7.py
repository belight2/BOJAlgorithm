#Authored by : chjh2129
import sys

input = sys.stdin.readline

def modify(p, val, tree, n) -> None:
  p += n
  tree[p] = val
  while p > 1:
    tree[p >> 1] = tree[p] + tree[p ^ 1]
    p >>= 1

def sumq(l, r, tree, n) -> int:
  ret = 0
  l, r = l + n, r + n
  while l < r:
    if l & 1:
      ret += tree[l]
      l += 1
    if r & 1:
      r -= 1
      ret += tree[r]
    l >>= 1
    r >>= 1
  return ret

def main() -> None:
  # input & init
  n, m = map(int, input().split())

  # 세그먼트 트리
  tree = [ 0 for _ in range(n * 2) ]

  # Query
  for cmd, a, b in (map(int, input().split()) for _ in range(m)):
    if cmd: modify(a-1, b, tree, n)
    else: 
      print(sumq(min(a, b)-1, max(a, b), tree, n))

sys.exit(main())