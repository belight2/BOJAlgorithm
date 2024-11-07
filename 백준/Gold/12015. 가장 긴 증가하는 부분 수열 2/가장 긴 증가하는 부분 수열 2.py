#Authored by : chjh2129
import sys
'''
  배열 정보를 {x, i}로 저장합니다. x는 배열의 값이고 i는 index 정보입니다.

  아래와 같이 x는 오름차순, i는 내림차순이되게 정렬합니다.

  {1, 3}
  {1, 2}
  {1, 1}
  {2, 4}

  세그먼트 트리는 LIS의 길이 정보를 저장하게 합니다. 초기에 모든 리프 노드 값이 0입니다.

  정렬한 배열은 순차 탐색하면서 [0, i] 범위에서 LIS의 최대 길이를 구합니다.

  이렇게 구한 LIS 길이에 +1한 값으로 세그먼트 트리를 갱신합니다.

  이를 모두 완료했다면 세그먼트 트리의 루트 값이 입력으로 주어진 배열의 LIS 길이가 됩니다.
'''
input = sys.stdin.readline

def update(p, val, tree, n) -> None:
  p += n
  tree[p] = val
  while p > 1:
    tree[p >> 1] = max(tree[p], tree[p^1])
    p >>= 1

def maxQuery(l, r, tree, n) -> int:
  ret = 0
  l, r = l + n, r + n
  while l < r:
    if l & 1:
      ret = max(ret, tree[l])
      l += 1
    if r & 1:
      r -= 1
      ret = max(ret, tree[r])
    l >>= 1
    r >>= 1
  return ret

def main() -> None:
  # input & init
  n = int(input())
  
  tree = [ 0 for _ in range(n * 2) ]

  a = [ ]
  for x, i in zip(list(map(int, input().split())), range(n)):
    a.append((x, i))
  
  a.sort(key=lambda x: (x[0], -x[1]))

  for _, ay in a:
    mx = maxQuery(0, ay, tree, n) + 1
    update(ay, mx, tree, n)

  print(tree[1])

sys.exit(main())