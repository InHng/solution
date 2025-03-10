for _ in range(int(input())):
    ans = 0
    input()
    for x in map(int, input().split()):
        ans ^= x
    print(ans)
