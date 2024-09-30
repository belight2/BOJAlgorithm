import sys
input = sys.stdin.readline
print = sys.stdout.write

def chk(x, y, length, image):
    cur = image[x][y]
    for i in range(x, x+length):
        for j in range(y, y+length):
            if(image[i][j] != cur ): return False
    return True

def recursion(x, y, length, image):
    if(chk(x,y,length,image)):
       print(str(image[x][y]))
       return
    length //= 2
    print("(")
    recursion(x,y,length,image)
    recursion(x,y+length,length,image)
    recursion(x+length,y,length,image)
    recursion(x+length,y+length,length,image)
    print(")")
    
length = int(input()) # 사각형 크기
# 흑백 영상 
image = [ [ 0 for i in range(length) ] for j in range(length) ]

for i in range(length):
    # 빠른 입출력 때 문자열을 입력받는다면
    # .rstrip()을 안쓸 경우 원하는 값을 얻을 수 없습니다.
    # 물론 지금 이 문제에서는 상관없지만
    # 문자열을 입력받는다면 그냥 무조건 해주는 편이 좋습니다.
    info = input().rstrip()
    for j in range(length):
        image[i][j] = int(info[j]) # 연산하기 편하게 형변환
        
recursion(0,0,length,image)
