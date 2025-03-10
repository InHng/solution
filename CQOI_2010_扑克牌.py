n, m = map(int, input().split())
all = list(map(int, input().split()))

def check(mid):
    cnt = 0
    for x in all:
        cnt += max(mid - x, 0)
    return cnt <= min(mid, m)

left, right = 0, 0x3f3f3f3f
while left + 1 < right:
    mid = (left + right) >> 1
    if check(mid):
        left = mid
    else:
        right = mid
print(left)
