import sys
input = sys.stdin.readline().rstrip

if __name__ == "__main__":
    s = input()
    s = list(s)
    s.sort()
    for i in range(len(s)-1, -1, -1):
        print(s[i], end='')