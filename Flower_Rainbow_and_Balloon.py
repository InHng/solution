import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

for _ in range(int(input())):
    n, m, k = map(int, input().split())
    s = input()
    left, right, ans = 0, n + 1, -1

    def check(len):
        hong, huang, bai = 0, 0, 0
        for i in range(len):
            if s[i] == 'r':
                hong += 1
            elif s[i] == 'y':
                huang += 1
            else:
                bai += 1
        if 2 * min(bai, m) + max(2 * hong + huang, 2 * huang + hong) >= k:
            return True
        for i in range(len, n):
            if s[i] == 'r':
                hong += 1
            elif s[i] == 'y':
                huang += 1
            else:
                bai += 1
            if s[i - len] == 'r':
                hong -= 1
            elif s[i - len] == 'y':
                huang -= 1
            else:
                bai -= 1
            if 2 * min(bai, m) + max(2 * hong + huang, 2 * huang + hong) >= k:
                return True
        return False

    while left + 1 < right:
        mid = (left + right) >> 1
        if check(mid):
            right = ans = mid
        else:
            left = mid
    print(ans)
