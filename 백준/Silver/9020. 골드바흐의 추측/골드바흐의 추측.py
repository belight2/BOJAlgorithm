def isPrime(n):
    if n == 1:
        return False
    else:
        for i in range(2, int(n**0.5)+1):
            if( n % i == 0 ):
                return False
    return True

def GoldBach(n, lst):
    gold = []
    
    for i in lst:
        if isPrime( n - i ):
            gold.append(i)
            
    if len(gold) == 1:
        return gold[0], n - gold[0]
    r = abs(2*gold[0] - n)
    ri = 0
    for i in range(1, len(gold)):
        m = abs(2*gold[i] - n)
        if r > m:
            r = m
            ri = i
    return gold[ri], n - gold[ri]
        
def main():
    T = int(input())
    for _ in range(T):      
        N = int(input())
        lst =list()
        
        for i in range(2, N):
            if isPrime(i):
                lst.append(i)

        x, y = GoldBach(N, lst)
        print(f"{x} {y}")
main()