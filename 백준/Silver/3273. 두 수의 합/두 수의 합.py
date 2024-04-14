import sys
input = sys.stdin.readline
f =  [ False for _ in range(2000001) ]
def main() -> None:
  n = int(input())
  a = list(map(int, input().rstrip().split()))
  x = int(input())
  ans = 0
  for data in a:
    f[data] = True
    if x - data < 0 or x - data > 2000000:
      continue
    if f[x-data] and x - data != data:
      ans+=1
  print(ans)

if __name__ == "__main__":
  main()