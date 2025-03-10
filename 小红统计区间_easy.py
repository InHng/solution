n, k = map(int, input().split())
left, right, cnt, ans = 0, 0, 0, 0
a = list(map(int, input().split()))
while right < n:
    cnt += a[right] # 加上右指针所在位置的数
    right += 1
    while cnt >= k: # 如果满足条件了，就寻找左边界
        cnt -= a[left]
        left += 1
    ans += left # 加上所有满足条件的数量(左边界左边都可以)
print(ans)
