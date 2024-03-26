import copy

def main():
    n, m = map( int, input().split())
    S = list()
    #체스판 입력받음
    for i in range(n):
        S.append(list(input()))
    S_black = copy.deepcopy(S)
    
    w = 'W'
    b = 'B'
    for i in range(n):
        for j in range(m):
            if i % 2 == 0:
                if j % 2 == 0:
                    if (S[i])[j] != w:
                        (S[i])[j] = '0'

                    if (S_black[i])[j] != b:
                        (S_black[i])[j] = '0'
                        
                else:
                    if (S[i])[j] != b:
                        (S[i])[j] = '0'

                    if (S_black[i])[j] != w:
                        (S_black[i])[j] = '0'
                    
            else:
                if j % 2 == 0:
                    if (S[i])[j] != b:
                        (S[i])[j] = '0'
                        
                    if (S_black[i])[j] != w:
                        (S_black[i])[j] = '0'
                else:
                    if (S[i])[j] != w:
                        (S[i])[j] = '0'
                        
                    if (S_black[i])[j] != b:
                        (S_black[i])[j] = '0'
    L = list()
    if n == 8 and m == 8:
        L.append(countColor(S, 0, 0))
        L.append(countColor(S_black, 0, 0))
    elif n == 8 and m > 8:
        for i in range(m-8+1):
            L.append(countColor(S,0,i))
            L.append(countColor(S_black, 0, i))
    elif n > 8 and m == 8:
        for i in range(n-8+1):
            L.append(countColor(S,i,0))
            L.append(countColor(S_black, i, 0))
    elif n > 8 and m > 8:
        for i in range(n-8+1):
            for j in range(m-8+1):
                L.append(countColor(S,i,j))
                L.append(countColor(S_black, i, j))
    print(min(L))
             

def countColor(S, a, b):
    c = 0
    for i in range(a, 8+a):
        for j in range(b, 8+b):
            if S[i][j] == '0':
                c += 1
    return c
main()