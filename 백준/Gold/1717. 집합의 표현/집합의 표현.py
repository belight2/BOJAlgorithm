#Authored by : chjh2129
import sys

'''
  parent 배열을 -1로 초기화한다.(노드 번호 x에 대해서 p[x] < 0일 때, x가 루트 노드)

  rank는 union이 된 횟수를 기준으로 평가함, rank가 큰 집합이 자식 노드가 많음

  rank가 작은 집합을 rank가 큰 집합으로 union 하는 것이 union by rank임.
'''
input = sys.stdin.readline

def find(x:int, p:list[int]) -> int:
  if p[x] < 0: return x
  p[x] = find(p[x], p)
  return p[x]

def union(x: int, y:int, p:list[int]) -> None:
  x = find(x, p)
  y = find(y, p)
  if x == y: return
  
  if p[x] == p[y]: p[x] -= 1 # 두 집합의 rank가 같다면 집합 하나를 임의로 rank 증가
  if p[x] > p[y]: x, y = y, x # y를 x에 union하기 위해 y의 rank가 더 크다면 swap
  
  p[y] = x #union

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