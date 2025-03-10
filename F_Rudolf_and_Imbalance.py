for _ in range(int(input())):
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    d = sorted(list(map(int, input().split())))
    f = sorted(list(map(int, input().split())))

    def check(mid):
        cnt, idx = 0, 0
        for i in range(1, n):
            if a[i] - a[i - 1] > mid:
                cnt += 1
                if cnt > 1:
                    return False
                idx = i
        if not cnt:
            return True
        down, up = a[idx] - mid, a[idx - 1] + mid
        right = k - 1
        for left in range(m):
            while ~right and d[left] + f[right] > up:
                right -= 1
            if ~right and d[left] + f[right] >= down:
                return True
        return False
    
    left, right = 0, 0xffffffff
    while left + 1 < right:
        mid = (left + right) >> 1
        if check(mid):
            right = mid
        else:
            left = mid
    print(left + 1)
