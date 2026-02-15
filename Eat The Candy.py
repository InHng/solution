import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

for _ in range(int(input())):
    n = int(input())
    a = [0] + list(map(int, input().split())) + [0]
    ans = 0
    pre, rear = [0 for _ in range(n + 2)], [0 for _ in range(n + 2)]
    b = a[:]
    for i in range(1, n + 1):
        pre[i] = pre[i - 1]
        diff = min(b[i], b[i - 1])
        pre[i] += diff
        b[i] -= diff
    b = a[:]
    for i in range(n, 0, -1):
        rear[i] = rear[i + 1]
        diff = min(b[i], b[i + 1])
        rear[i] += diff
        b[i] -= diff
    for i in range(1, n + 1):
        ans = max(ans, pre[i - 1] + a[i] + rear[i + 1])
    print(ans)
