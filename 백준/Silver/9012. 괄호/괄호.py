import sys
input = sys.stdin.readline

def main():
    n = int(input())
    stack = list()
    for i in range(n):
        result = True
        s = input().strip()
        for j in range(len(s)):
            stack.append( s[ j ] )
            
            if stack[-1] == ")":
                stack.pop(-1)
                if not stack:
                    result = False
                    break
                stack.pop(-1)
        if stack or not result:
            print("NO")
            stack.clear()
        elif not stack:
            print("YES")             
main()