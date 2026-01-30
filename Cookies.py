import sys
import heapq
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, k, x = map(int, input().split())
a = [0] + sorted(list(map(int, input().split())), reverse = True)
q = [(-a[1] * k, 1, 0, k)]  # [累加和, 最小值多的下标, 比最小值更大的元素个数, 最小值个数]
ans = []
for _ in range(x):
    mx, id, pre, cnt = heapq.heappop(q)
    ans.append(str(-mx))
    if pre:     # 拿出前一个，再放入一个最小值
        heapq.heappush(q, (mx + a[id - 1] - a[id], id, pre - 1, cnt + 1))
    if id < n:  # 拿出当前最小值，放入一个更小的
        heapq.heappush(q, (mx + a[id] - a[id + 1], id + 1, cnt - 1, 1))
print("\n".join(ans))
