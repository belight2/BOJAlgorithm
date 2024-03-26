from collections import deque
import sys
input = sys.stdin.readline
print = sys.stdout.write

dx = [ 1, 0, -1, 0 ]
dy = [ 0, 1, 0, -1 ]

test_case = int(input())

for _ in range(test_case):
    M, N, K = map(int, input().split())
    worm = 0
    vis = [ [ False for i in range(M) ] for j in range(N) ] 
    board = [ [ 0 for i in range(M) ] for j in range(N) ]
    Q = deque()
    for __ in range(K):
        y, x = map(int, input().split())
        board[x][y] = 1
    
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1 and not vis[i][j]:
                worm += 1
                Q.append((i,j))
                vis[i][j] = True
                while Q:
                    curX, curY = Q.popleft()
                    for d in range(4):
                        nx = curX + dx[d]
                        ny = curY + dy[d]
                        if( nx < 0 or nx >= N or ny < 0 or ny >= M): continue
                        if(vis[nx][ny] or board[nx][ny] != 1) : continue
                        vis[nx][ny] = True
                        Q.append((nx,ny))
    print(str(worm)+'\n')
