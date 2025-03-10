for _ in range(int(input())):
    n = int(input())
    for i in range(2, n + 1):
        if i * i > n:
            break
        while n % i == 0:
            n //= i
            print(i, end = " ")
    if n != 1:
        print(n, end = "")
    print()
