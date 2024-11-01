#Authored by : chjh2129
import sys
'''
  이 문제는 출발점이 정해져있지 않고 negative cycle이 있는지 묻고있는 문제입니다.

  문제의 지문을 읽어보면 그래프가 연결그래프라고 말하고 있지 않습니다.

  여러 개의 component로 이루어진 그래프가 입력으로 주어졌을 때,

  임의의 정점을 출발지로 해서 벨만-포드 알고리즘을 돌렸다면,

  출발지와는 다른 컴포넌트에서 음의 사이클이 있는 경우, 문제를 틀릴 수 있습니다.

  아래의 반례를 한 번 보시면 이해가 될겁니다.
  ------------------------------------------
  1
  6 5 1
  1 2 3
  2 3 5
  1 3 2
  4 5 1
  5 6 2
  6 4 10
  -> 이 테스트케이스에서 출발지를 1로 잡고 벨만-포드를 돌리면 NO를 출력한다. (YES가 정답)
  -------------------------------------------

  따라서, 모든 정점을 출발점으로 보고 거리 테이블을 0으로 초기화한 상태로 벨만-포드를 시작합니다.

  처음엔 음수 가중치를 가진 간선 정보만 갱신이 됩니다.

  만약, negative cycle을 있다면 n번째 완화에서도 거리 테이블이 갱신이 됩니다.
'''
input = sys.stdin.readline

def main() -> None:
  t = int(input())
  for _ in range(t):
    # input & init
    n, m, w = map(int, input().split())

    # 간선 정보 
    edges = [ ]
    
    # 거리 배열
    d = [ 0 for _ in range(n + 1) ]

    # 간선 정보 
    for s, e, t in (map(int, input().split()) for _ in range(m)):
      edges.append((s, e, t))
      edges.append((e, s, t))
    
    # 웜홀 정보
    for s, e, t in (map(int, input().split()) for _ in range(w)):
      edges.append((s, e, -t))
    
    # solve(Bellman-Ford Algorithm)
    ans = "NO"
    for i in range(n):
      for s, e, t in edges:
        if d[s] + t >= d[e]:
          continue
        d[e] = d[s] + t
        if i == n-1: ans = "YES"
    
    print(ans)
          
        
sys.exit(main())