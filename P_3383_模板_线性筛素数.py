import sys
input = sys.stdin.readline

n, q = map(int, input().split())

isprime = [1 for _ in range(n + 1)]
primes = []
for i in range(2, n + 1):
    if isprime[i]:
        primes.append(i)
        for j, x in enumerate(primes):
            if i * x > n:
                break
            isprime[i * x] = 0
            if i % x == 0:
                break
            
for _ in range(q):
    print(primes[int(input()) - 1])
