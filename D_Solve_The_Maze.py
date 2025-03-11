from queue import deque
from collections import defaultdict

def solve():
    n, m = map(int, input().split())
    g = [list(input()) for _ in range(n)]
    mp = defaultdict(map)
    for i in range(n):
        for j in range(m):
            if g[i][j] == 'G':
                mp[(i, j)] = 1
            if g[i][j] == 'B':
                for x, y in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
                    if 0 <= x < n and 0 <= y < m:
                        if g[x][y] == 'G':  # 好人和坏人挨在一起
                            print("No")
                            return
                        elif g[x][y] == '.':    # 用墙把坏人围起来
                            g[x][y] = '#'

    if g[-1][-1] == '#' and mp:
        print("No")
        return
    
    q = deque()
    q.append((n - 1, m - 1))
    while q:
        x, y = q.popleft()
        for xx, yy in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
            if not (0 <= xx < n and 0 <= yy < m):
                continue
            if g[xx][yy] not in ['.', 'G']:
                continue
            q.append((xx, yy))
            if g[xx][yy] == 'G':
                mp[(xx, yy)] = 0
            g[xx][yy] = '#'

    for x in mp.values():
        if x:
            print("No")
            return
    print("Yes")


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
