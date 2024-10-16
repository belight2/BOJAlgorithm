#Authored by : chjh2129
import sys

input = sys.stdin.readline

'''
  parent 배열을 -1로 초기화

  임의의 노드 번호 x에 대해서 abs(p[x])는 집합의 크기를 의미함.

  사이즈가 작은 집합이 큰 집합에 union되게 구현함.

  문제를 풀이할 때 집합의 크기가 필요한 문제에서 사용시 유용함.
'''

def find(x:int, p:list[int]) -> int:
  if p[x] < 0: return x
  p[x] = find(p[x], p)
  return p[x]

def union(x: int, y:int, p:list[int]) -> None:
  x = find(x, p)
  y = find(y, p)
  if x == y: return
  
  if p[x] > p[y]: x, y = y, x # y를 x에 union하기 위해 집합의 크기가 y가 더 크다면 swap
  
  p[x] += p[y] # 집합의 크기를 더한다.
  p[y] = x
  
  
def main() -> None:
  # input
  n, m = map(int, input().split()) 

  # init
  p:list[int] = [-1] * (n+1)

  # solve & output
  for _ in range(m):
    q, u, v = map(int, input().split())
    if not q: 
      union(u, v, p)
    elif find(u, p) == find(v, p): 
      print("YES")
    else: print("NO")

sys.exit(main())