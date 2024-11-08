#Authored by : chjh2129
import sys
'''
  구간 합 세그먼트를 두 개 선언합니다.

  dist : x = 0으로부터의 거리를 저장하는 세그먼트 트리

  cnt : x에 심어진 나무의 개수

  x에 나무를 심는다고 가정하면 두 세그먼트 트리를 이용하여 나무를 심는 비용을 구할 수 있습니다.

  왼쪽에 있는 나무들의 거리 합 = dist.sumq(0, x) - cnt.sumq(0, x) * x
  오른쪽에 있는 나무들의 거리 합 = dist.sumq(x+1, MX) - cnt.sumq(x+1, MX) * x

  이 두 값을 더하면 x에 나무를 심을 때, 드는 비용을 구할 수 있습니다.

  주의할 점은 나무를 같은 위치에 여러 번 심을 수도 있고, 오버플로우도 조심해야합니다.
'''
input = sys.stdin.readline

def update(p, val, tree, n) -> None:
  p += n
  tree[p] += val
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
  MX = 200005 # 좌표가 0 ~ 200,000임 
  MOD = int(1e9) + 7

  n = int(input())

  cnt = [ 0 for _ in range(MX * 2) ]
  dist = [ 0 for _ in range(MX * 2) ]

  x = int(input())
  update(x, 1, cnt, MX)
  update(x, x, dist, MX)

  # Query
  ans = 1  
  for x in (int(input()) for _ in range(n-1)):
    left = abs(sumQuery(0, x, dist, MX) - sumQuery(0, x, cnt, MX) * x)
    right = abs(sumQuery(x+1, MX, dist, MX) - sumQuery(x+1, MX, cnt, MX) * x)

    ans = (ans * (left + right)) % MOD

    update(x, 1, cnt, MX)
    update(x, x, dist, MX)
  
  print(ans % MOD)

sys.exit(main())