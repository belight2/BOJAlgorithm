import sys
input = sys.stdin.readline().rstrip

if __name__ == "__main__":
    x, y = input().split()
    
    x_first = 0
    x_last = len(x)
    first= 0
    last = len(x)
    Min = len(y)
    result = 0

    while True:
        if last > len(y):
            break

        for i, j in zip(range(x_first, last), range(first, last) ):
            if x[i] != y[j]:
                result += 1
            
        if Min > result:
            Min = result

        first += 1
        last += 1
        result = 0

    print(Min)