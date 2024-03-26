import sys
input = sys.stdin.readline

def LeftCount(lst):
    if len(lst) == 1:
        return 0
    C = 1
    a = len(lst)
    b = lst[a-1]
    for i in range(len(lst)-3, -1, -1):
        check = True
        c = i + 1
        d = lst[i]
        m =  ( b - d ) / ( a - c )
        for j in range( i+1, len(lst)-1):
            if not StraightLine(m , a, b, j+1, lst[j]):
                check = False
        if check:
            C+=1
    return C
    
def RightCount(lst):
    if len(lst) == 1:
        return 0
    C = 1
    a = 1
    b = lst[0]
    
    for i in range(2, len(lst)):
        check = True
        c = i + 1
        d = lst[i]
        m =  ( b - d ) / ( a - c )
        for j in range(1, i):
            if not StraightLine( m , a, b, j+1, lst[j]):
                 check = False
        if check:
            C += 1
    return C
        
def StraightLine( m, a, b, x, y):
    if m * ( x - a ) + b > y:
        return True
    return False

def main():
    N = int(input())
    lst = list( map( int, input().split() ) )
    CountList = [0] * N
    
    for i in range(N):
        LC = LeftCount(lst[:i+1])
        RC = RightCount(lst[i:])
        CountList[i] = LC+RC
    print(max(CountList))
    
main()