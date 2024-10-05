def main():
    N = int(input())
    L = set()
    for i in range(N):
        s = input()
        L.add( (s, len(s)) )
    L = list(L)
    L = sorted(L, key = lambda x :  (x[1], x[0]) )
    
    for i in range(len(L)):
        print((L[i])[0])
    
    
main()