#Authored by : chjh2129
import sys
'''
  갱신 함수 update를 값 변경이 아닌 덧셈 연산으로 변경하여 풀이
'''

input = sys.stdin.readline

def update(p, val, tree, n) -> None:
  p += n
  tree[p] += val # 변경이 아닌, 덧셈 연산 수행
  while p > 1:
    tree[p >> 1] = tree[p] + tree[p ^ 1]
    p >>= 1

def sumQuery(l, r, tree, n) -> int:
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

  tree = [ 0 for _ in range(2 * n) ]

  # Query
  for cmd, a, b in (map(int, input().split()) for _ in range(m)):
    if cmd & 1: update(a-1, b, tree, n)
    else:
      print(sumQuery(a-1, b, tree, n))
  
sys.exit(main())