import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

for _ in range(int(input())):
    n, m = map(int, input().split())
    a, b = list(map(int, input().split())), list(map(int, input().split()))
    if n < m:
        print("NO")
        continue
    c = []
    i, j = 0, 0
    while i < n and j < m:
        if a[i] >= b[j]:
            c.append(a[i])
            j += 1
        i += 1
    print("YES" if len(c) >= m else "NO")
