#Authored by : chjh2129
import sys
'''
  간선 정보를 가중치가 큰 순서부터 순차적으로 merge를 진행하여 풀이합니다.

  임의의 간선 (w, u, v)가 merge가 되고 출발지(st)와 목적지(en)가 같은 집합에 속하게되었다면.

  이전에 연결된 간선의 가중치는 w보다 크거나 같습니다. 이후에 연결할 간선 정보는 w보다 작거나 같으므로,

  출발지에서 목적지로 들고갈 수 있는 중량의 최댓값은 w가 됩니다.
'''
input = sys.stdin.readline

def find(x: int, P: list[int]) -> int:
  if P[x] < 0: return x
  P[x] = find(P[x], P)
  return P[x]

def union(x: int, y: int, P: list[int]) -> None:
  x = find(x, P)
  y = find(y, P)
  if x == y: return
  if P[x] == P[y]: P[x] -= 1
  if P[x] > P[y]: x, y = y, x
  P[y] = x

def main() -> None:
  # 섬 개수, 다리 개수
  N, M = map(int, input().split())
  
  # 간선 정보 저장
  E = [ ( w, u, v ) for u, v, w in (map(int, input().split()) for _ in range(M)) ]

  # 출발지와 목적지
  st, en = map(int, input().split())
  
  # init 
  P: list[int] = [ -1 for _ in range(N+1) ]
  E.sort()

  # solve
  while E:
    w, u, v = E.pop()
    union(u, v, P)
    if(find(st, P) == find(en, P)):
      # 출력 후 종료
      print(w)
      break

    
sys.exit(main())