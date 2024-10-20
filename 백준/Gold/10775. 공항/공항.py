#Authored by : chjh2129
import sys
'''
  g가 주어졌을 때, 1번부터 g번 중 아직 도킹하지 않은 게이트를 찾는 쿼리를 최적화하는 것이 핵심인 문제

  idx[x] = x를 가지게 한 다음, 좌표 압축을 응용하여 도킹할 게이트를 찾는 쿼리를 최적화할 수 있습니다.

  idx[x] = x인 값을 찾으면 아직 도킹하지 않은 게이트 번호를 찾았다고 할 수 있습니다.

  도킹을 했다면 idx[x]의 값을 1 감소하여 x-1로 갱신하여 idx[x-1]에서 도킹할 게이트 번호를 찾도록 구현합니다.

  찾은 번호가 0이라면 더 이상 도킹이 불가능하다고 판단할 수 있습니다. 
'''
input = sys.stdin.readline



'''
  저도 이번에 파이썬으로 풀어보면서 알게된 사실이지만 파이썬은 정말 재귀에 약한 것 같습니다.

  sys.setrecursionlimit()을 사용해 재귀 깊이를 재정의하여 제출했더니 pypy기준 메모리초과를 받습니다.

  대충 알아보니 파이썬은 함수 호출 비용이 매우 커서 재귀로 구현시 이런 일이 생긴다고 합니다.

  아래는 find함수를 비재귀로 구현한 코드입니다.

  재귀는 코드를 간결하게 작성할 수 있고, 저의 기준에서는 가독성이 훨씬 좋아서 자주 사용하는데 C++에서는 이런 일이 없어서 잘 몰랐네요.

  그리고 한 가지 팁으로 파이썬으로 코드를 제출할 때 pypy로 제출하는 것을 추천드립니다.

  이유는 저도 잘 모르지만 대부분의 경우 python 3에서 제출했을 때 TLE를 받는 코드가 pypy에서 AC를 받습니다.
'''
def find(x: int, idx: list[int]) -> int:
  root: int = x
  
  # 도킹할 수 있는 게이트 번호를 찾는다.
  while idx[root] != root:
    root = idx[root]

  # 좌표 압축을 진행한다.
  while idx[x] != x:
    nxt = idx[x]
    idx[x] = root
    x = nxt
  
  return root

def main() -> None:
  # input
  n: int = int(input())
  m: int = int(input())

  # init
  idx: list[int] = list(range(0, n+1))

  # solve
  ans: int = 0
  for _ in range(m):
    g: int = int(input())
    g = find(g, idx) # [1, g] 중 도킹가능한 게이트 번호를 찾는다.
    if g == 0: break
    idx[g] -= 1
    ans += 1

  # output 
  print(ans)

sys.exit(main())