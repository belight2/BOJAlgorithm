import io, os, sys
from collections import deque
from itertools import count

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def main() -> None:
  for t in count(1):
    n, m = map(int, input().split())
    if n == 0:
      break
    solve(n, m, t)
    
def solve(N: int, M: int, testCase: int) -> None:
  # input
  G = [ [] for _ in range(N+1) ]
  P = [ 0 for _ in range(N+1) ]

  for _ in range(M):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)
  
  # solve
  treeCount: int = 0
  
  for i in range(1, N+1):
    if P[i] != 0:
      continue
    isTree: bool = True
    Q: deque = deque()
    Q.append(i)
    
    while Q:
      cur: int = Q.pop()
      for nxt in G[cur]:
        if P[cur] == nxt:
          continue
        if P[nxt] != 0:
          isTree = False
          continue
        P[nxt] = cur
        Q.append(nxt)
    
    if isTree:
      treeCount += 1
  
  # output
  print(f"Case {testCase}: ", end="")
  if treeCount == 0:
    print("No trees.")
  elif treeCount == 1:
    print("There is one tree.")
  else:
    print(f"A forest of {treeCount} trees.")

main()