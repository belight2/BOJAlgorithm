import math
def main():
    T = int(input())
    for i in range(T):
        sx, sy, ex, ey = map(int, input().split() )
        n = int(input())
        C = list()
        count = 0
        for j in range(n):
            C.append( tuple( map( int, input().split() ) ) )
        #원의 중심 좌표와 출발, 도착 좌표의 거리가 반지름보다 작으면 카운트

        for j in range(n):
            x, y, r =C[j]
            #출발좌표와 거리
            dis_one = math.sqrt( ( x - sx ) ** 2 + ( y - sy ) ** 2 )
            #도착좌표와 거리
            dis_two = math.sqrt( ( x - ex ) **2 + ( y - ey ) ** 2 )
            # 거리 비교
            if dis_one < r :
                count += 1
            if dis_two < r :
                count += 1
            if dis_one < r and dis_two < r:
                count -= 2
            

        print(count)
main()
