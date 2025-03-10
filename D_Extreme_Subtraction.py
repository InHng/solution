for _ in range(int(input())):
    n = int(input())
    a = [0] + list(map(int, input().split()))
    diff = [0 for _ in range(n + 1)]
    cnt = 0
    for i in range(1, n + 1):
        diff[i] = a[i] - a[i - 1]
        if i != 1 and diff[i] < 0:
            cnt -= diff[i]
    print("YES" if cnt <= a[1] else "NO")
