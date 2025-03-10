n = int(input())
all = list(map(int, input().split()))
k = int(input())
if k == 1:
    exit(print(max(all)))

def check(mid):
    cnt = 0
    for x in all:
        if x >= mid:
            cnt += (x - mid + k - 2) // (k - 1)
    return cnt > mid

left, right = 0, 0x3f3f3f3f
while left + 1 < right:
    mid = (left + right) >> 1
    if check(mid):
        left = mid
    else:
        right = mid
print(left + 1)
