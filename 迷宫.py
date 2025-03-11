from queue import deque

H, W = map(int, input().split())
a = [input() for _ in range(H)]
start = None
for i in range(H):
    for j in range(W):
        if a[i][j] == 'S':
            start = (i, j)
            break
memo = [[[0, 0] for _ in range(W)] for _ in range(H)]

memo[start[0]][start[1]][0] = 1
q = deque()
q.append((start[0], start[1], 0, 0))
while q:
    x, y, key, step = q.popleft()
    if a[x][y] == 'E':
        exit(print(step))
    for xx, yy, next_key in ((x + 1, y, key), (x - 1, y, key), (x, y + 1, key), (x, y - 1, key)):
        if a[xx][yy] == 'K':
            next_key = 1
        if memo[xx][yy][key] or a[xx][yy] == 'W' or (not key and a[xx][yy] == 'D'):
            continue
        memo[xx][yy][key] = 1
        q.append((xx, yy, next_key, step + 1))
print(-1)
