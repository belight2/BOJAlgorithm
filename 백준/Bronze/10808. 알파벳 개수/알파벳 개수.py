import sys
from collections import Counter
input = sys.stdin.readline
if __name__ == "__main__":
  s = input().rstrip()
  freq = [0] * (ord('z') - ord('a') +1)
  for c in s:
    freq[ord(c) - ord('a')] += 1
  for data in freq:
    print(data, end=' ')

