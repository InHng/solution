n = int(input())
path = []
st = [0 for _ in range(n + 1)]

def dfs():
    if len(path) == n:
        print(*path)
        return
    for i in range(1, n + 1):
        if not st[i]:
            st[i] = 1
            path.append(i)
            dfs()
            path.pop()
            st[i] = 0

dfs()
