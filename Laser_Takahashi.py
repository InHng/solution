import sys
import math
input = lambda: sys.stdin.readline().strip()

n, q = map(int, input().split())
monsters = []
for i in range(n):
    x, y = map(int, input().split())
    monsters.append((math.atan2(y, x), i))
monsters.sort(key=lambda x: x[0])

cnt = []
original_idx = [0] * n

if n > 0:
    cnt.append(1)
    original_idx[monsters[0][1]] = 0
    now = 0
    
    for i in range(1, n):
        if monsters[i][0] == monsters[i-1][0]:
            cnt[now] += 1
        else:
            now += 1
            cnt.append(1)
        original_idx[monsters[i][1]] = now

pre = [0] * (len(cnt) + 1)
for i in range(len(cnt)):
    pre[i + 1] = pre[i] + cnt[i]

results = []
cnt_size = len(cnt)

for _ in range(q):
    left, right = map(int, input().split())
    left, right = left - 1, right - 1
    original_left = original_idx[left]
    original_right = original_idx[right]
    if original_left >= original_right:
        print(pre[original_left + 1] - pre[original_right])
    else:
        print(pre[original_left + 1] - pre[0] + pre[cnt_size] - pre[original_right])
