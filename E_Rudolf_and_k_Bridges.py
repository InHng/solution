from heapq import *

for _ in range(int(input())):
    n, m, k, d = map(int, input().split())
    pre = [0 for _ in range(n)]
    for i in range(n):
        a = list(map(int, input().split()))
        q = []
        heappush(q, (1, 0))
        for j in range(1, m):
            while q and q[0][1] < j - d - 1:
                heappop(q)
            heappush(q, (q[0][0] + a[j] + 1, j))
        while q and q[0][1] != m - 1:
            heappop(q)
        pre[i] = q[0][0]
    cnt = sum(pre[:k])
    ans = cnt
    for i in range(k, n):
        cnt += pre[i] - pre[i - k]
        ans = min(ans, cnt)
    print(ans)
