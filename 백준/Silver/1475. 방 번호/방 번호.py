import sys
input = sys.stdin.readline().rstrip

def main() -> None:
  n = input()
  lst = [ *[n.count(x) for x in "012345678" ] ]
  lst[6] = (lst[6] + n.count('9')+1) // 2
  print(max(lst))
  
if __name__ == "__main__":
  main()