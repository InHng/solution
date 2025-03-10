import sys
input = sys.stdin.readline
from queue import deque

for _ in range(int(input())):
    n, m = map(int, input().split())
    g = [input() for _ in range(n)]
    memo = [[0 for _ in range(m)] for _ in range(n)]
    sx, sy = None, None
    for i in range(n):
        for j in range(m):
            if g[i][j] == 'P':
                sx, sy = i, j
    q = deque()
    ans = 0

    def bfs2(X, Y):
        global ans
        q.clear()
        q.append((X, Y, 0))
        memo = [[0 for _ in range(m)] for _ in range(n)]
        while q:
            x, y, step = q.popleft()
            memo[x][y] = 1
            if g[x][y] == 'E':
                ans += step
                return False
            for xx, yy in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
                if not (0 <= xx < n and 0 <= yy < m):
                    continue
                if memo[xx][yy] or g[xx][yy] == '#':
                    continue
                q.append((xx, yy, step + 1))
        return True
    
    def bfs1(X, Y):
        global ans
        q.append((X, Y, 0))
        while q:
            x, y, step = q.popleft()
            memo[x][y] = 1
            if g[x][y] == 'K':
                ans += step
                return bfs2(x, y)
            for xx, yy in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
                if not (0 <= xx < n and 0 <= yy < m):
                    continue
                if memo[xx][yy] or g[xx][yy] == '#' or g[xx][yy] == 'E':
                    continue
                q.append((xx, yy, step + 1))
        return True
    
    flag = bfs1(sx, sy)
    if flag:
        print("No solution")
    else:
        print(ans)
