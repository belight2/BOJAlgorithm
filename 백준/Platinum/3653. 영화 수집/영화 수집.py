#Authored by : chjh2129
import sys
'''
  < 초기화 방법 >
  DVD 개수 n과 쿼리 수행 횟수 m이 주어졌을 때, n + m 크기로 배열로 세그먼트 트리를 구성합니다.
  크기가 n+m인 배열은 범위에 따라 아래와 같이 초기화합니다
 
  [0, n-1] : 1, DVD가 있는 곳
  [n, n+m) : 0, DVD가 없는 곳

  번호가 거꾸로 쌓여있으므로 번호에 따라 위치 정보를 알려주는 idx 배열을 선언합니다.

  idx[x] = 0, x번 DVD의 위치가 현재 0임  

  세그먼트 트리를 각 테스트케이스마다 새로 구성해야 함. 
  이 부분이 중요한 것도 아닌데 까다로워서 그냥 class로 만들어서 사용함.
  (파이썬은 class 구현 없이 풀이함.)
 
  ----------------------------------------  
 
  < 풀이하는 방법 >
  
  각 쿼리마다, x번 dvd를 위에 올려야합니다. 
  
  int new_pos = n;

  idx[x]의 위치를 new_pos로 갱신해줍니다. 
  x번 보다 위에 있는 dvd 개수를 세기 위해서는 세그먼트 트리에서 (idx[x] + 1, MAX)을 범위로 합 쿼리를 수행하면 됩니다.
'''
input = sys.stdin.readline

def update(p, val, tree, n) -> None:
  p += n
  tree[p] = val
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

def solve() -> None:
  # input & init
  n, m = map(int, input().split())

  # idx[i]: i번 DVD의 위치
  idx = list(range(n, -1, -1)) 

  # 세그먼트 트리
  tree = [ 0 for _ in range(n+m) ] + [ 1 for _ in range(n) ] + [ 0 for _ in range(m) ]

  cur = n+m - 1
  while cur > 0:
    tree[cur] = tree[cur << 1] + tree[cur << 1 | 1]
    cur -= 1
  
  # Query
  ans = list()
  npos = n
  for x in list(map(int, input().split())):
    ans.append(sumQuery(idx[x] + 1, n + m, tree, n + m))

    update(idx[x], 0, tree, n+m)
    idx[x] = npos
    update(idx[x], 1, tree, n+m)

    npos += 1

  # output
  print(*ans)

def main() -> None:
  t = int(input())
  for _ in range(t):
    solve()

sys.exit(main())