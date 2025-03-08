from functools import cache

for _ in range(int(input())):
    n, m = map(int, input().split())

    @cache
    def dfs(x):
        if x % 3:
            return False
        a, b = x * 2 / 3, x / 3
        if a == m or b == m:
            return True
        if a < m and b < m:
            return False
        return (a > m and dfs(a)) or (b > m and dfs(b))
    
    if m == n:
        print("YES")
    elif m > n:
        print("NO")
    else:
        print("YES" if dfs(n) else "NO")
