for _ in range(int(input())):
    n = int(input())
    s = ["F"] + list(input())
    ans = float('inf')
    g = [[0, 0]] + [list(map(int, input().split())) for _ in range(n)]

    stack = [(1, 0)]
    while stack:
        i, cnt = stack.pop()
        if g[i] == [0, 0]:
            ans = min(ans, cnt)
        if g[i][0]:
            stack.append((g[i][0], cnt + (s[i] != 'L')))
        if g[i][1]:
            stack.append((g[i][1], cnt + (s[i] != 'R')))
    print(ans)
