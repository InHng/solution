for _ in range(int(input())):
    n = int(input())
    a = [0] + list(map(int, input().split()))
    pre, suf = [1 for _ in range(n + 2)], [1 for _ in range(n + 2)]
    pre[1] = suf[n] = 1
    for i in range(2, n):
        pre[i] = ((a[i + 1] - a[i]) if a[i] - a[i - 1] < a[i + 1] - a[i] else 1)
    for i in range(n - 1, 1, -1):
        suf[i] = ((a[i] - a[i - 1]) if a[i] - a[i - 1] > a[i + 1] - a[i] else 1)
    for i in range(1 ,n):
        pre[i] += pre[i - 1]
    for i in range(n, 0, -1):
        suf[i] += suf[i + 1]
    for _ in range(int(input())):
        x, y = map(int, input().split())
        print((suf[y + 1] - suf[x + 1]) if x > y else (pre[y - 1] - pre[x - 1]))
