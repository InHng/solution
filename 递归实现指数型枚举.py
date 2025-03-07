n = int(input())
path = []

def dfs(pos):
    for i, x in enumerate(path):
        if i and x < path[i - 1]:
            return
    print(*path)
    for i in range(pos, n + 1):
        path.append(i)
        dfs(i + 1)
        path.pop()

dfs(1)
