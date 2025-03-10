L, n, m = map(int, input().split())
all = [0]
for _ in range(n):
    all.append(int(input()))
all.append(L)

def check(mid):
    cnt, i, now = 0, 0, 0
    while i <= n:
        i += 1
        if all[i] - all[now] < mid:
            cnt += 1
        else:
            now = i
    return cnt <= m

left, right = -1, 0x3f3f3f3f
while left + 1 < right:
    mid = (left + right) >> 1
    if check(mid):
        left = mid
    else:
        right = mid
print(left)
