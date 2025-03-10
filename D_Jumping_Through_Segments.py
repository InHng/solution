for _ in range(int(input())):
    n = int(input())
    op = []
    for __ in range(n):
        op.append(list(map(int, input().split())))

    def check(mid):
        now = [0, 0]
        for x, y in op:
            now[0] = max(now[0] - mid, x)
            now[1] = min(now[1] + mid, y)
            if now[0] > now[1]:
                return False
        return True

    left, right = -1, 0x3f3f3f3f
    while left + 1 < right:
        mid = (left + right) >> 1
        if check(mid):
            right = mid
        else:
            left = mid
    
    print(left + 1)
