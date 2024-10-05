def isPrime(n):
    if n == 1:
        return False
    else:
        for i in range(2, int(n**0.5)+1):
            if( n % i == 0 ):
                return False
    return True

def main():
    while True:
        n = int(input())
        cnt = 0
        if n == 0: break
        for i in range(n+1, 2*n+1):
            if isPrime(i):
                cnt += 1
        print(cnt)
main()