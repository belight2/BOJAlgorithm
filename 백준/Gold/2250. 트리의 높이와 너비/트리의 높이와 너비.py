import sys

sys.setrecursionlimit(10000)

input = sys.stdin.readline

N = int(input())
L = [0] * (N+1)
R = [0] * (N+1)
column = dict()
root = set(range(1, N+1))

cnt = 0
def inorder(cur:int, level:int)->None:
  global cnt
  if cur == -1:
    return
  
  inorder(L[cur], level+1)
  
  cnt += 1
  column[level][0] = min(cnt, column[level][0])
  column[level][1] = max(cnt, column[level][1])

  inorder(R[cur], level+1)

def solve():
  for _ in range(N):
    cur, left, right = map(int, input().split())
    L[cur] = left
    R[cur] = right
    root.discard(left)
    root.discard(right)
  
  r = root.pop()
  # init
  for level in range(1, N+1):
    column[level] = [int(1e9), -1]

  inorder(r, 1)

  ans = [ 0, 0 ]
  for level in range(1, N+1):
    if column[level][1] - column[level][0] + 1 > ans[1]:
      ans[0] = level
      ans[1] = column[level][1] - column[level][0] + 1

  print(*ans)  

sys.exit(solve())