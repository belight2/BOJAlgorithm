import sys
input = sys.stdin.readline
print = sys.stdout.write

def main():
    n = int(input())
    lst = [0] * 10001
    for i in range(n):
        lst[int(input())] += 1
    for i in range(1, 10001):
        while lst[i] > 0:
            print(str(i)+'\n')
            lst[i] -= 1
    
main()
