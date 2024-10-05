import sys
input = sys.stdin.readline

def ListFind(lst, e):
    idx = -1
    for i in range(len(lst)):
        if lst[i] == e:
            idx = i
            return idx
    return idx

def MaxFind( lst, bound , clear):
    for i in range( len(lst)-1, -1, -1):
        if i < bound and clear[i] == 0:
            return i
    return -1
    
def ShortestTime( b, c ):
    if b[-1] > c[-1]:
        return -1
    
    slice_line = [0] * len(c)
    
    i = 0
    while True:
        if i == len(c):
            break
        for j in range(len(b)):
            if b[j] > c[i]:
                slice_line[i] = j
                break
        if slice_line[i] == 0 and c[i] >= max(b):
            slice_line[i] = len(b)
        i += 1
    t = 0
    # 1이면 화물에 실은 박스라는 뜻
    clear = [0] * len(b)
    while True:
        if ListFind(clear, 0) == -1:
            break
        
        for i in range(len(c)):
            if 0 != slice_line[i]:
                k = MaxFind(b, slice_line[i], clear)
                if k != -1:
                    clear[k] = 1
        t += 1
    return t
    

    
    
def main():
    Crain_N = int(input())
    Crain_W = list( map( int, input().split() ) )
    Box_N = int(input())
    Box_W = list( map( int, input().split() ) )

    Crain_W.sort()
    Box_W.sort()
    print(ShortestTime(Box_W, Crain_W))
    
main()