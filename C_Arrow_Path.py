from queue import deque

def solve():
    n = int(input())
    g = [input() for _ in range(2)]
    memo = [[0 for _ in range(n)] for _ in range(2)]
    q = deque()
    q.append((0, 0))
    while q:
        x, y = q.popleft()
        if (x, y) == (1, n - 1):
            print("YES")
            return
        if memo[x][y]:
            continue
        memo[x][y] = 1
        for xx, yy in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
            if 0 <= xx < 2 and 0 <= yy < n:
                yy += (1 if g[xx][yy] == '>' else -1)
                if 0 <= xx < 2 and 0 <= yy < n:
                    q.append((xx, yy))
    print("NO")

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
