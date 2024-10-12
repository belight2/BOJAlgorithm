#Authored by : chjh2129
import io, os, sys
from collections import defaultdict

# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
input = sys.stdin.readline

def preorder(cur: str, G: defaultdict[ str, list[str]] ) -> None:
  if cur == '.':
    return
  print(cur, end='')
  preorder(G[cur][0], G)
  preorder(G[cur][1], G)

def inorder(cur: str, G: defaultdict[ str, list[str] ]) -> None:
  if cur == '.':
    return
  inorder(G[cur][0], G)
  print(cur, end='')
  inorder(G[cur][1], G)

def postorder(cur: str, G: defaultdict[ str, list[str] ]) -> None:
  if cur == '.':
    return
  postorder(G[cur][0], G)
  postorder(G[cur][1], G)
  
  print(cur, end='')

def main() -> None:
  # input
  N = int(input())
  
  # 인접 리스트 선언
  G: defaultdict[str, list[str]] = defaultdict(list)

  for _ in range(N):
    cur, *child = input().rstrip().split()
    G[cur] = child

  # output
  preorder('A', G)
  print()
  inorder('A', G)
  print()
  postorder('A', G)
  


sys.exit(main())