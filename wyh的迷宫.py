import sys
input = sys.stdin.readline
from queue import deque

for _ in range(int(input())):
    n, m = map(int, input().split())
    g = [list(input()) for _ in range(n)]
    visit = set()
    start, end = None, None
    ans = "NO"
    for i in range(n):
        for j in range(m):
            if g[i][j] == 's':
                start = (i, j)
            if g[i][j] == 't':
                end = (i, j)
    q = deque()
    q.append(start)
    visit.add(start)

    while q:
        x, y = q.popleft()
        if (x, y) == end:
            ans = "YES"
            break
        for xx, yy in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
            if not (0 <= xx < n and 0 <= yy < m):
                continue
            if g[xx][yy] == 'x':
                continue
            if (xx, yy) in visit:
                continue
            visit.add((xx, yy))
            q.append((xx, yy))
    
    print(ans)
